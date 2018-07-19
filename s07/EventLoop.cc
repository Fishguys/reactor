#include "EventLoop.h"
#include "TimerQueue.h"

#include "../base/logging.h"
#include "Poller.h"
#include "Channel.h"

#include <assert.h>
#include <poll.h>
#include <iostream>
#include <string>

#include <sys/eventfd.h>
#include <unistd.h>

using namespace std;

__thread EventLoop* t_loopInThisThread = 0;
const int kPollTimeMs = 1000;

static int createEventfd()
{
	int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
	if (evtfd < 0)
	{
		LOG_SYSERR << "Failed in eventfd";
		abort();
	}
	return evtfd;
}

EventLoop::EventLoop()
  : looping_(false),
	quit_(false),
	callingPendingFunctors_(false),
    threadId_(this_thread::get_id()),
	poller_(new Poller(this)),
	timerQueue_(new TimerQueue(this)),
	wakeupFd_(createEventfd()),
	wakeupChannel_(new Channel(this, wakeupFd_))
{
	LOG_INFO << "EventLoop created " << this << " in thread ";
	cout << threadId_ << endl;
	if (t_loopInThisThread)
	{
		LOG_FATAL << "Another EventLoop " << t_loopInThisThread
				  << " exists in this thread ";
		cout << threadId_ << endl;
	}
	else
	{
		t_loopInThisThread = this;
	}
	wakeupChannel_->setReadCallback(
		std::bind(&EventLoop::handleRead,this));
	// we are always reading the wakeupfd
	wakeupChannel_->enableReading();
}

EventLoop::~EventLoop()
{
	assert(!looping_);
	::close(wakeupFd_);
	t_loopInThisThread = NULL;
}

void EventLoop::loop()
{
	assert(!looping_);
	assertInLoopThread();
	looping_ = true;
	quit_ = false;
	
	while(!quit_)
	{
		activeChannels_.clear();
		pollReturnTime_ = poller_->poll(kPollTimeMs, &activeChannels_);
		for(ChannelList::iterator it = activeChannels_.begin(); it != activeChannels_.end(); it++)
		{
			(*it)->handleEvent(pollReturnTime_);
		}
		doPendingFunctors();
	}
	LOG_TRACE << "EventLoop " << this << " stop looping";
	looping_ = false;
}

void EventLoop::abortNotInLoopThread()
{

	cout << "EventLoop::abortNotInLoopThread - EventLoop " << this
            << " was created in threadId_ = ";
	cout << threadId_ << endl;
	cout  << ", current thread id = ";
	cout << this_thread::get_id() << endl;
	LOG_FATAL << "exit";
}

void EventLoop::quit()
{
	quit_ = true;
	//wakeup();
	//如果非当前线程需要唤醒
	if(!isInLoopThread())
	{
		wakeup();
	}
	
}

void EventLoop::updateChannel(Channel* channel)
{
  assert(channel->ownerLoop() == this);
  assertInLoopThread();
  poller_->updateChannel(channel);
}

TimerId EventLoop::runAt(const Timestamp& time, const TimerCallback& cb)
{
	return timerQueue_->addTimer(cb, time, 0.0);
}

TimerId EventLoop::runAfter(double delay, const TimerCallback& cb)
{
	Timestamp time(addTime(Timestamp::now(), delay));
	return runAt(time, cb);
}

TimerId EventLoop::runEvery(double interval, const TimerCallback& cb)
{
	Timestamp time(addTime(Timestamp::now(), interval));
	return timerQueue_->addTimer(cb, time, interval);
}

void EventLoop::doPendingFunctors()
{
	std::vector<Functor> functors;
	callingPendingFunctors_ = true;
	
	{
		std::lock_guard<std::mutex> lck(mutex_);
		functors.swap(pendingFunctors_);
	}
	
	for(auto func : functors)
	{
		func();
	}
	
	callingPendingFunctors_ = false;
}

void EventLoop::runInLoop(const Functor& cb)
{
	if(isInLoopThread()){
		cb();
	}else{
		queueInLoop(cb);
	}
}

void EventLoop::queueInLoop(const Functor& cb)
{
	{
		std::lock_guard<std::mutex> lc(mutex_);
		pendingFunctors_.push_back(cb);
	}
	
	//这里唤醒poll的情况有两种，其他线程调用queueloop，那么唤醒是必须的
	//还有如果是当前IO线程正在调用pending functor，那么也必须唤醒，
	//也是为了pending factor执行完毕以后及时执行新加入的factor
	if(!isInLoopThread() || callingPendingFunctors_)
	{
		wakeup();
	}
}

void EventLoop::wakeup()
{
	uint64_t one = 1;
	ssize_t n = ::write(wakeupFd_,&one,sizeof(one));
	if (n != sizeof one)
	{
		LOG_ERROR << "EventLoop::handleRead() reads " << n << " bytes instead of 8";
	}
}

void EventLoop::handleRead()
{
	uint64_t one = 1;
	ssize_t n = ::read(wakeupFd_, &one, sizeof(one));
	if( n!=sizeof(uint64_t))
	{
		LOG_ERROR << "EventLoop::handleRead() reads " << n << " bytes instead of 8";
	}
}

//只在当前Loop中使用这个函数
void EventLoop::removeChannel(Channel* channel)
{
	assert(channel->ownerLoop() == this);
	assertInLoopThread();
	poller_->removeChannel(channel);
}