#ifndef NET_CHANNEL_H
#define NET_CHANNEL_H

#include <functional>
class Timestamp;
class EventLoop;
//Channel 通过enableXXX类函数来注册fd上的新事件
///
/// A selectable I/O channel.
///
/// This class doesn't own the file descriptor.
/// The file descriptor could be a socket,
/// an eventfd, a timerfd, or a signalfd
class Channel
{
public:
	typedef std::function<void()> EventCallback;
	typedef std::function<void(Timestamp)> ReadEventCallback;
	Channel(EventLoop* loop, int fd);
	~Channel();

	void handleEvent(Timestamp receiveTime);
	void setReadCallback(const ReadEventCallback& cb)
	{ readCallback_ = cb; }
	void setWriteCallback(const EventCallback& cb)
	{ writeCallback_ = cb; }
	void setErrorCallback(const EventCallback& cb)
	{ errorCallback_ = cb; }
	void setCloseCallback(const EventCallback& cb)
	{ closeCallback_ = cb; }
	int fd() const { return fd_; }
	int events() const { return events_; }
	void set_revents(int revt) { revents_ = revt; }
	bool isNoneEvent() const { return events_ == kNoneEvent; }

	void enableReading() { events_ |= kReadEvent; update(); }
	void enableWriting() { events_ |= kWriteEvent; update(); }
	void disableWriting() { events_ &= ~kWriteEvent; update(); }
	void disableAll() { events_ = kNoneEvent; update(); }
	boll isWriting()const{ return events_ & kWriteEvent; }
	// for Poller
	int index() { return index_; }
	void set_index(int idx) { index_ = idx; }

	EventLoop* ownerLoop() { return loop_; }
	Channel(const Channel&) = delete;
	const Channel& operator=(const Channel&) = delete;
private:
	void update();

	static const int kNoneEvent;
	static const int kReadEvent;
	static const int kWriteEvent;

	EventLoop* loop_;
	const int  fd_;
	int        events_;
	int        revents_;
	int        index_; // used by Poller.Poller中保存一个channel数组

	bool eventHandling_;

	ReadEventCallback readCallback_;
	EventCallback writeCallback_;
	EventCallback errorCallback_;
	EventCallback closeCallback_;
};
#endif  //NET_CHANNEL_H
