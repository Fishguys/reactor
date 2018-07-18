#include "TcpConnection.h"

#include "Channel.h"
#include "EventLoop.h"
#include "Socket.h"
#include "../base/logging.h"
#include <unistd.h>

TcpConnection::TcpConnection(EventLoop* loop,
		const std::string& name,
		int sockfd,
		const InetAddress& localAddr,
		const InetAddress& peerAddr)
  : m_pLoop(CHECK_NOTNULL(loop)),
    m_strName(name),
	m_state(kConnecting),
	m_pSocket(new Socket(sockfd)),
	m_pChannel(new Channel(loop,sockfd)),
	m_localAddr(localAddr),
	m_peerAddr(peerAddr)
	{
		LOG_DEBUG << "TcpConnection::ctor[" << m_strName << "] at "
				  << this << " fd=" << sockfd;
		m_pChannel->setReadCallback(std::bind(&TcpConnection::handleRead, this));
	}

TcpConnection::~TcpConnection()
{
	LOG_DEBUG << "TcpConnection::dtor[" << m_strName << "] at "
				  << this << " fd=" << m_pChannel->fd();
}

void TcpConnection::handleRead()
{
	char buf[65536];
	ssize_t n = ::read(m_pChannel->fd(), buf, sizeof(buf));
	m_msgCallback(shared_from_this(), buf, n);
	// FIXME: close connection if n == 0
}

void TcpConnection::connectEstablished()
{
	m_pLoop->assertInLoopThread();
	assert(m_state == kConnecting);
	setState(kConnected);
	m_pChannel->enableReading();
	
	m_connCallback(shared_from_this());
}