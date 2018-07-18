#ifndef NET_TIMERQUEUE_H
#define NET_TIMERQUEUE_H

#include <set>
#include <vector>
#include <mutex>
#include <memory>

#include "../base/timestamp.h"
#include "Callbacks.h"
#include "Channel.h"

class EventLoop;
class Timer;
class TimerId;

/// A best efforts timer queue.
/// No guarantee that the callback will be on time.

//TimerQueue类只需要一个定时器对象，关于这个timerfd的回调函数交由channel管理
//channel类的handleEvent函数完成事件的分发，
class TimerQueue
{
public:
	TimerQueue(EventLoop* loop);
	~TimerQueue();

	/// Schedules the callback to be run at given time,
	/// repeats if @c interval > 0.0.
	///
	/// Must be thread safe. Usually be called from other threads.
	TimerId addTimer(const TimerCallback& cb,
				   Timestamp when,
				   double interval);

	// void cancel(TimerId timerId);

private:

	// FIXME: use unique_ptr<Timer> instead of raw pointers.
	//typedef std::unique_ptr<Timer> TimerPtr;
	typedef std::pair<Timestamp, Timer*> Entry;
	typedef std::set<Entry> TimerList;

	// called when timerfd alarms
	void handleRead();
	// move out all expired timers
	std::vector<Entry> getExpired(Timestamp now);
	void reset(const std::vector<Entry>& expired, Timestamp now);

	//每次插入新的定时器完成都需要判断是否要设置新的定时器超时时间
	//因此返回bool用于判断是否需要设置
	bool insert(Timer* timer);

	EventLoop* loop_;
	const int timerfd_;
	Channel timerfdChannel_;
	// Timer list sorted by expiration
	TimerList timers_;
};

#endif  // MUDUO_NET_TIMERQUEUE_H
