#ifndef NET_TCPCONNECTION_H
#define NET_TCPCONNECTION_H

#include "Buffer.h"
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
	/// Internal use only.for TcpServe and TcpClient
	void setCloseCallback(const CloseCallback& cb){ m_closeCallback = cb;}
	// called when TcpServer accepts a new connection
	void connectEstablished();   // should be called only once
	// called when TcpServer has removed me from its map
	void connectDestroyed();  // should be called only once
private:
	//kConnection:未连接，kConnected：已连接，kDisconnecting：shutDown办关闭，kDisconnected:已关闭
	enum StateE { kConnecting, kConnected, kDisconnecting, kDisconnected};
	
	void setState(StateE s){ m_state = s; }
	void handleRead(Timestamp receiveTime);
	void handleWrite();
	void handleClose();
	void handleError();

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
	CloseCallback m_closeCallback;
	Buffer m_inputBuffer;
};
#endif //NET_TCPCONNECTION_H