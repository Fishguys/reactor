#ifndef NET_EVENTLOOP_H
#define NET_EVENTLOOP_H

#include <thread>
#include <memory>
#include <vector>

using namespace std;

class Channel;
class Poller;

class EventLoop
{
public:

	EventLoop();
	~EventLoop();

	//Loops forever.
	//Must be called in the same thread as creation of the object.
	void loop();
	
	void quit();
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
	std::unique_ptr<Poller> poller_;
	ChannelList activeChannels_;
};

#endif  // NET_EVENTLOOP_H
