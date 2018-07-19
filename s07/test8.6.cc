/**********************test case for 8.7******************/
#include "TcpServer.h"
#include "EventLoop.h"
#include "InetAddress.h"
#include "Buffer.h"
#include <stdio.h>

void onConnection(const TcpConnectionPtr& conn)
{
	if (conn->connected())
	{
		printf("onConnection(): new connection [%s] from %s\n",
		conn->name().c_str(),
		conn->peerAddress().toHostPort().c_str());
	}
	else
	{
		printf("onConnection(): connection [%s] is down\n",
		conn->name().c_str());
	}
}

void onMessage(const TcpConnectionPtr& conn,
               Buffer* buf,
			   Timestamp receiveTime)
{
	printf("onMessage(): received %zd bytes from connection [%s] at %s\n",
		buf->readableBytes(), conn->name().c_str(), receiveTime.toFormattedString().c_str());
	
	printf("onMessage(): [%s]\n",buf->retrieveAsString().c_str());
}

int main()
{


	InetAddress listenAddr(1111);
	EventLoop loop;

	TcpServer server(&loop, listenAddr);
	server.setConnCallback(onConnection);
	server.setMsgCallback(onMessage);
	server.start();

	loop.loop();
}
