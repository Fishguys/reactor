#include <functional>
#include "EventLoopThread.h"
#include "EventLoop.h"

EventLoopThread::EventLoopThread()
	: loop_(NULL),
	  exiting_(false)
{
	
}

EventLoopThread::~EventLoopThread()
{
	exiting_ = true;
	if(loop_ != NULL)
	{
		loop_->quit();
		thread_->join();
	}
}

EventLoop* EventLoopThread::startLoop()
{
	thread_.reset(new std::thread(std::bind(&EventLoopThread::threadFunc,this)));
	
	{
		std::unique_lock<std::mutex> lck(mutex_);
		while(loop_ == NULL)
		{
			cond_.wait(lck);
		}
	}
	
	return loop_;
}

void EventLoopThread::threadFunc()
{
	EventLoop loop;
	
	{
		std::unique_lock<std::mutex> lck(mutex_);
		loop_ = &loop;
		cond_.notify_all();
	}
	
	loop.loop();
	loop_ = NULL;
}