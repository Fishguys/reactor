#ifndef NET_TCPSERVER_H
#define NET_TCPSERVER_H

#include "Callbacks.h"
#include "TcpConnection.h"

#include <map>
#include <memory>

class Acceptor;
class EventLoop;

class TcpServer
{
public:
	TcpServer(EventLoop* loop, const InetAddress& listenAddr);
	~TcpServer();  // force out-line dtor, for scoped_ptr members.
	
	/// Starts the server if it's not listenning.
	///
	/// It's harmless to call it multiple times.
	/// Thread safe.
	void start();
	
	///set connection callback.
	///not thread safe.
	void setConnCallback(ConnectionCallback cb){ m_connCallback = cb; }
	///set message callback.
	///not thread safe.
	void setMsgCallback(MessageCallback cb){ m_msgCallback = cb; }
private:
	
	///Not thread safe, but in loop
	void newConnection(int sockfd, const InetAddress& peerAddr);
	typedef std::map<std::string, TcpConnectionPtr> TcpConnectionMap;
	
	EventLoop* m_pLoop;		//the acceptor loop
	const std::string m_strName;
	std::unique_ptr<Acceptor> m_pAcceptor;
	ConnectionCallback m_connCallback;
	MessageCallback m_msgCallback;
	bool m_bStarted;
	int m_nextConnId;		//always in loop thread
	TcpConnectionMap m_mapConn;
	
};
#endif //NET_TCPSERVER_H