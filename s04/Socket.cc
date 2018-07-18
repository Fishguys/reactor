#include "Socket.h"

#include "InetAddress.h"
#include "SocketsOps.h"

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h>  // bzero

Socket::~Socket()
{
	sockets::close(m_sockfd);
}

void Socket::bindAddress(const InetAddress& localaddr)
{
	sockets::bindOrDie(m_sockfd,localaddr.getSockAddr());
}
	
void Socket::listen()
{
	sockets::listenOrDie(m_sockfd);
}

int Socket::accept(InetAddress* peeraddr)
{
	struct sockaddr_in addr;
	bzero(&addr, sizeof(struct sockaddr_in));
	int connfd = sockets::accept(m_sockfd, &addr);
	peeraddr->setSockAddrInet(addr);
	return connfd;
}

void Socket::setReuseAddr(bool on)
{
	int optval = on ? 1 : 0;
	::setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR,
		   &optval, sizeof optval);
	// FIXME CHECK
}