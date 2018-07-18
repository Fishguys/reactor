#ifndef NET_INETADDRESS_H
#define NET_INETADDRESS_H

#include <string>

#include <netinet/in.h>

//Wrapper of sockaddr_in
//This is an POD interface class

class InetAddress
{
public:
	//Constructs an endpoint with given port number.
	//Mostly used in TcpServer listening
	explicit InetAddress(uint16_t port);
	
	//Constructs an endpoint with given ip an port.
	//@c ip should be '1.2.3.4'
	InetAddress(const std::string& ip, uint16_t port);
	
	//Constructs an endpoint with given sockaddr_in
	//Mostly used when accepting new connections
	InetAddress(const struct sockaddr_in& addr):m_addr(addr){}
	
	std::string toHostPort()const;
	const struct sockaddr_in& getSockAddr() const{return m_addr;}
	void setSockAddrInet(const struct sockaddr_in& addr){ m_addr = addr; }
private:
	struct sockaddr_in m_addr;
};
#endif