#include "Acceptor.h"

#include "../base/logging.h"
#include "EventLoop.h"
#include "InetAddress.h"
#include "SocketsOps.h"

Acceptor::Acceptor(EventLoop* loop, const InetAddress& listenAddr)
	: m_pLoop(loop),
	  m_acceptSocket(sockets::createNonblockingOrDie()),
	  m_acceptChannel(loop, m_acceptSocket.fd()),
	  m_blistenning(false)
{
	m_acceptSocket.setReuseAddr(true);
	m_acceptSocket.bindAddress(listenAddr);
	m_acceptChannel.setReadCallback(
		std::bind(&Acceptor::handleRead, this));
}

void Acceptor::listen()
{
	m_pLoop->assertInLoopThread();
	m_blistenning = true;
	m_acceptSocket.listen();
	m_acceptChannel.enableReading();
}

void Acceptor::handleRead()
{
	m_pLoop->assertInLoopThread();
	InetAddress peerAddr(0);
	int connfd = m_acceptSocket.accept(&peerAddr);
	if(connfd >= 0){
		if(m_newConnCallback){
			m_newConnCallback(connfd, peerAddr);
		}else{
			sockets::close(connfd);
		}
	}
}