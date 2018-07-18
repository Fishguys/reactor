#include "TcpServer.h"

#include "../base/logging.h"
#include "Acceptor.h"
#include "EventLoop.h"
#include "SocketsOps.h"

#include <functional>

#include <stdio.h>  // snprintf

TcpServer::TcpServer(EventLoop* loop, const InetAddress& listenAddr)
  : m_pLoop(CHECK_NOTNULL(loop)),
    m_strName(listenAddr.toHostPort()),
	m_pAcceptor(new Acceptor(m_pLoop, listenAddr)),
	m_bStarted(false),
	m_nextConnId(1)
{
	using namespace std::placeholders;		//bind
	m_pAcceptor->setNewConnectionCallback(std::bind(&TcpServer::newConnection, this, _1, _2));
}

TcpServer::~TcpServer()
{
	
}

void TcpServer::start()
{
	if(!m_bStarted) m_bStarted = true;
	
	if(!m_pAcceptor->listenning())
	{
		m_pLoop->runInLoop(std::bind(&Acceptor::listen,m_pAcceptor.get()));
	}
}

void TcpServer::newConnection(int sockfd, const InetAddress& peerAddr)
{
	m_pLoop->assertInLoopThread();
	char buf[32];
	snprintf(buf, sizeof(buf), "#%d", m_nextConnId);
	++m_nextConnId;
	std::string connName = m_strName + buf;
	
	LOG_INFO << "TcpServer::newConnection [" << m_strName
			 << "] - new Connection [" << connName
			 <<"] from " << peerAddr.toHostPort();
	InetAddress localAddr(sockets::getLocalAddr(sockfd));
	
	//FIXME poll with zero timeout to double confirm the new connection
	//TcpConnectionPtr conn(new TcpConnection(m_pLoop, connName, sockfd, localAddr, peerAddr));
	TcpConnectionPtr conn = std::make_shared<TcpConnection> (m_pLoop, connName, sockfd, localAddr, peerAddr);
	m_mapConn[connName] = conn;
	conn->setConnCallback(m_connCallback);
	conn->setMsgCallback(m_msgCallback);
	conn->connectEstablished();
}