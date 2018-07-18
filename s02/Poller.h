#ifndef NET_POLLER_H
#define NET_POLLER_H

#include <map>
#include <vector>

#include "../base/timestamp.h"
#include "EventLoop.h"

struct pollfd;
class Channel;

///
/// IO Multiplexing with poll(2).
///
/// This class doesn't own the Channel objects.
class Poller
{
public:
	typedef std::vector<Channel*> ChannelList;

	Poller(EventLoop* loop);
	~Poller();

	/// Polls the I/O events.
	/// Must be called in the loop thread.
	Timestamp poll(int timeoutMs, ChannelList* activeChannels);

	/// Changes the interested I/O events.
	/// Must be called in the loop thread.
	void updateChannel(Channel* channel);

	void assertInLoopThread() { ownerLoop_->assertInLoopThread(); }
	Poller(const Poller&) = delete;
	const Poller& operator=(const Poller&) = delete;
private:
	void fillActiveChannels(int numEvents,
						  ChannelList* activeChannels) const;

	typedef std::vector<struct pollfd> PollFdList;
	typedef std::map<int, Channel*> ChannelMap;

	EventLoop* ownerLoop_;
	PollFdList pollfds_;		//把pollfd数组缓存起来
	ChannelMap channels_;
};

#endif  // NET_POLLER_H
