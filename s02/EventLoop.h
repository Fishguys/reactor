#ifndef NET_EVENTLOOP_H
#define NET_EVENTLOOP_H

#include "../base/timestamp.h"
#include "Callbacks.h"
#include "TimerId.h"

#include <thread>
#include <memory>
#include <vector>

using namespace std;

class Channel;
class Poller;
class TimerQueue;

class EventLoop
{
public:

	EventLoop();
	~EventLoop();

	//Loops forever.
	//Must be called in the same thread as creation of the object.
	void loop();
	
	void quit();
	
	//Time when poll returns,usually means data arrival.
	Timestamp pollReturnTime()const{ return pollReturnTime_; }
	
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

private:
	EventLoop(const EventLoop&);
	const EventLoop& operator=(const EventLoop&);
	
	typedef std::vector<Channel*> ChannelList;
	
	void abortNotInLoopThread();

	bool looping_; /* atomic */
	bool quit_; /*atomic*/
	const thread::id threadId_;
	Timestamp pollReturnTime_;
	std::unique_ptr<Poller> poller_;
	std::unique_ptr<TimerQueue> timerQueue_;
	ChannelList activeChannels_;
};

#endif  // NET_EVENTLOOP_H
