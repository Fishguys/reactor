#include "EventLoop.h"

#include "../base/logging.h"

#include <assert.h>
#include <poll.h>
#include <iostream>
#include <string>
using namespace std;

__thread EventLoop* t_loopInThisThread = 0;

EventLoop::EventLoop()
  : looping_(false),
    threadId_(this_thread::get_id())
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

  ::poll(NULL, 0, 5*1000);

  LOG_INFO << "EventLoop " << this << " stop looping";
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

