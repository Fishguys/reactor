#ifndef NET_TCPCONNECTION_H
#define NET_TCPCONNECTION_H

#include "Callbacks.h"
#include "InetAddress.h"

class Channel;
class EventLoop;
class Socket;

/// TCP connection, for both client and server usage.
//负责管理建立连接以后的connfd,注册connfd上的各种poll事件的回调函数
class TcpConnection : public std::enable_shared_from_this<TcpConnection>
{
public:
	/// Constructs a TcpConnection with a connected sockfd
	///
	/// User should not create this object.
	TcpConnection(EventLoop* loop,
			const std::string& name,
			int sockfd,
			const InetAddress& localAddr,
			const InetAddress& peerAddr);
	~TcpConnection();
	
	EventLoop* getLoop()const {return m_pLoop;}
	const std::string& name() const { return m_strName; }
	const InetAddress& localAddress() { return m_localAddr; }
	const InetAddress& peerAddress() { return m_peerAddr; }
	bool connected() const { return m_state == kConnected; }
	
	void setConnCallback(ConnectionCallback cb){ m_connCallback = cb; }
	void setMsgCallback(MessageCallback cb){ m_msgCallback = cb; }
	
	// called when TcpServer accepts a new connection
	void connectEstablished();   // should be called only once
private:
	enum StateE { kConnecting, kConnected, };
	
	void setState(StateE s){ m_state = s; }
	void handleRead();
	
	EventLoop* m_pLoop;
	std::string m_strName;
	StateE m_state;
	// we don't expose those classes to client.
	std::unique_ptr<Socket> m_pSocket;
	std::unique_ptr<Channel> m_pChannel;
	InetAddress m_localAddr;
	InetAddress m_peerAddr;
	ConnectionCallback m_connCallback;
	MessageCallback m_msgCallback;
};
#endif //NET_TCPCONNECTION_H