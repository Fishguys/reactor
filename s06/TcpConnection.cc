#include "TcpConnection.h"

#include "Channel.h"
#include "EventLoop.h"
#include "Socket.h"
#include "../base/logging.h"
#include "SocketsOps.h"
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
		m_pChannel->setWriteCallback(std::bind(&TcpConnection::handleWrite,this));
		m_pChannel->setErrorCallback(std::bind(&TcpConnection::handleError,this));
		m_pChannel->setCloseCallback(std::bind(&TcpConnection::handleClose,this));
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
	if (n > 0){
		m_msgCallback(shared_from_this(), buf, n);
	}
	else if (0 == n){
		handleClose();
	}
	else{
		handleError();
	}
	
	// FIXME: close connection if n == 0
}

void TcpConnection::connectEstablished()
{
	m_pLoop->assertInLoopThread();
	assert(m_state == kConnecting);
	setState(kConnected);
	m_pChannel->enableReading();
	
	m_connCallback(shared_from_this());		//打印连接信息
}

void TcpConnection::connectDestroyed()
{
	m_pLoop->assertInLoopThread();
	assert(m_state == kConnected);
	setState(kDisconnected);
	m_pChannel->disableAll();
	m_connCallback(shared_from_this());		//打印连接信息

	m_pLoop->removeChannel(m_pChannel.get());		//移除POLLER中相应的channel
}

void TcpConnection::handleWrite()
{

}

void TcpConnection::handleClose()
{
	m_pLoop->assertInLoopThread();
	LOG_TRACE << "TcpConnection::handleClose state = " << m_state;
	assert(m_state == kConnected);
	//we don't close fd, leave it to dtor,so we can find leaks easily.
	m_pChannel->disableAll();
	//must be the last line
	m_closeCallback(shared_from_this());		//用于移除TcpServer中相应的TcpConnection
}

void TcpConnection::handleError()
{
	int err = sockets::getSocketError(m_pSocket->fd());
	LOG_ERROR << "TcpConnection::handleError [" << m_strName << "] - SO_ERROR = "
		<< err << " " << strerror_tl(err);
}