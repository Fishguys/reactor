#ifndef NET_ACCEPTOR_H
#define NET_ACCEPTOR_H

#include <functional>
#include "Channel.h"
#include "Socket.h"

class EventLoop;
class InetAddress;

// Acceptor of incoming TCP connections.
class Acceptor
{
public:
	typedef std::function<void (int sockfd,
	                              const InetAddress&)> NewConnectionCallback;
	Acceptor(EventLoop* loop, const InetAddress& listenAddr);

	void setNewConnectionCallback(const NewConnectionCallback& cb)
	{ m_newConnCallback = cb; }

	bool listenning() const { return m_blistenning; }
	void listen();

	private:
	void handleRead();

	EventLoop* m_pLoop;
	Socket m_acceptSocket;
	Channel m_acceptChannel;
	NewConnectionCallback m_newConnCallback;
	bool m_blistenning;
};
#endif // NET_ACCEPTOR_H