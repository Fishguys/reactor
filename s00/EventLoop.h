#ifndef NET_EVENTLOOP_H
#define NET_EVENTLOOP_H

#include <thread>
using namespace std;

class EventLoop
{
public:

	EventLoop();
	~EventLoop();

	void loop();

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
	
	void abortNotInLoopThread();

	bool looping_; /* atomic */
	const thread::id threadId_;
};

#endif  // NET_EVENTLOOP_H
