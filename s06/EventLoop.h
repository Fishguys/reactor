#ifndef NET_EVENTLOOP_H
#define NET_EVENTLOOP_H

#include "../base/timestamp.h"
#include "Callbacks.h"
#include "TimerId.h"

#include <thread>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class Channel;
class Poller;
class TimerQueue;

class EventLoop
{
public:
	typedef std::function<void()> Functor;
	
	EventLoop();
	~EventLoop();

	//Loops forever.
	//Must be called in the same thread as creation of the object.
	void loop();
	
	void quit();
	
	//Time when poll returns,usually means data arrival.
	Timestamp pollReturnTime()const{ return pollReturnTime_; }
	
	/// Runs callback immediately in the loop thread.
	/// It wakes up the loop, and run the cb.
	/// If in the same loop thread, cb is run within the function.
	/// Safe to call from other threads.
	void runInLoop(const Functor& cb);
	/// Queues callback in the loop thread.
	/// Runs after finish pooling.
	/// Safe to call from other threads.
	void queueInLoop(const Functor& cb);
  
	///
	/// Runs callback at 'time'.
	///
	TimerId runAt(const Timestamp& time, const TimerCallback& cb);
	///
	/// Runs callback after @c delay seconds.
	///
	TimerId runAfter(double delay, const TimerCallback& cb);
	///
	/// Runs callback every @c interval seconds.
	///
	TimerId runEvery(double interval, const TimerCallback& cb);

	// internal use only
	void wakeup();
	void updateChannel(Channel* channel);
	// void removeChannel(Channel* channel);

	void assertInLoopThread()
	{
		if (!isInLoopThread())
		{
			abortNotInLoopThread();
		}
	}

	bool isInLoopThread() const { return threadId_ == this_thread::get_id(); }

	void removeChannel(Channel* channel);
private:
	EventLoop(const EventLoop&);
	const EventLoop& operator=(const EventLoop&);

	void abortNotInLoopThread();
	void handleRead();
	void doPendingFunctors();
	
	typedef std::vector<Channel*> ChannelList;
	
	bool looping_; /* atomic */
	bool quit_; /*atomic*/
	bool callingPendingFunctors_; /*atomic*/
	const thread::id threadId_;
	Timestamp pollReturnTime_;
	std::unique_ptr<Poller> poller_;
	std::unique_ptr<TimerQueue> timerQueue_;
	int wakeupFd_;
	//unlike in TimerQueue,which is an internal class,
	//we don't expose Channel to client.
	std::unique_ptr<Channel> wakeupChannel_;
	ChannelList activeChannels_;
	std::mutex mutex_;
	std::vector<Functor> pendingFunctors_;		//Guarded by mutex;
};

#endif  // NET_EVENTLOOP_H
