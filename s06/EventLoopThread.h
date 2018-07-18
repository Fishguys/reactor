#ifndef NET_EVENTLOOPTHREAD_H
#define NET_EVENTLOOPTHREAD_H

#include <condition_variable>
#include <mutex>
#include <thread>
#include <memory>

class EventLoop;

class EventLoopThread
{
public:
	EventLoopThread();
	~EventLoopThread();
	const EventLoopThread& operator=(const EventLoopThread&) = delete;
	EventLoopThread(const EventLoopThread&) = delete;
	
	EventLoop* startLoop();
private:
	void threadFunc();
	
	EventLoop* loop_;
	bool exiting_;
	std::unique_ptr<std::thread> thread_;
	std::mutex mutex_;
	std::condition_variable cond_;
};

#endif  //  NET_EVENTLOOPTHREAD_H