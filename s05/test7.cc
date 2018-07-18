/**********************test case for 8.4******************/
#include "Acceptor.h"
#include "EventLoop.h"
#include "InetAddress.h"
#include "SocketsOps.h"
#include <stdio.h>
#include <unistd.h>

void newConnection1(int sockfd, const InetAddress& peerAddr)
{
	printf("newConnection(): accepted a new connection from %s\n",
		peerAddr.toHostPort().c_str());
	char buf[] = "newConnection1: How are you?\n";
	ssize_t n = ::write(sockfd, buf, sizeof(buf));
	printf("write %d Bytes to sockfd %d\n",n,sockfd);
	sockets::close(sockfd);
}

void newConnection2(int sockfd, const InetAddress& peerAddr)
{
	printf("newConnection(): accepted a new connection from %s\n",
		peerAddr.toHostPort().c_str());
	::write(sockfd, "newConnection2: How are you?\n", 13);
	sockets::close(sockfd);
}

int main()
{
	printf("main(): pid = %d\n", getpid());

	InetAddress listenAddr1(1111);
	//InetAddress listenAddr2(2222);
	
	EventLoop loop;

	Acceptor acceptor1(&loop, listenAddr1);
	//Acceptor acceptor2(&loop, listenAddr2);
	
	acceptor1.setNewConnectionCallback(newConnection1);
	acceptor1.listen();

	//acceptor2.setNewConnectionCallback(newConnection2);
	//acceptor2.listen();
	
	loop.loop();
}