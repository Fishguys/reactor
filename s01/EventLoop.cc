#include "EventLoop.h"

#include "../base/logging.h"
#include "Poller.h"
#include "Channel.h"

#include <assert.h>
#include <poll.h>
#include <iostream>
#include <string>
using namespace std;

__thread EventLoop* t_loopInThisThread = 0;
const int kPollTimeMs = 1000;

EventLoop::EventLoop()
  : looping_(false),
	quit_(false),
    threadId_(this_thread::get_id()),
	poller_(new Poller(this))
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
}

EventLoop::~EventLoop()
{
	assert(!looping_);
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
		poller_->poll(kPollTimeMs, &activeChannels_);
		for(ChannelList::iterator it = activeChannels_.begin(); it != activeChannels_.end(); it++)
		{
			(*it)->handleEvent();
		}
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
  // wakeup();
}

void EventLoop::updateChannel(Channel* channel)
{
  assert(channel->ownerLoop() == this);
  assertInLoopThread();
  poller_->updateChannel(channel);
}
