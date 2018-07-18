#include "InetAddress.h"

#include "SocketsOps.h"

#include <strings.h>  // bzero
#include <netinet/in.h>

//     /* Structure describing an Internet socket address.  */
//     struct sockaddr_in {
//         sa_family_t    sin_family; /* address family: AF_INET */
//         uint16_t       sin_port;   /* port in network byte order */
//         struct in_addr sin_addr;   /* internet address */
//     };

//     /* Internet address. */
//     typedef uint32_t in_addr_t;
//     struct in_addr {
//         in_addr_t       s_addr;     /* address in network byte order */
//     };

static const in_addr_t kInaddrAny = INADDR_ANY;
static_assert(sizeof(InetAddress) == sizeof(struct sockaddr_in),
				"InetAddress.cc: sizeof(InetAddress) != sizeof(struct sockm_addrin)");

InetAddress::InetAddress(uint16_t port)
{
	bzero(&m_addr, sizeof m_addr);
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = sockets::hostToNetWork32(kInaddrAny);
	m_addr.sin_port = sockets::hostToNetWork16(port);
}

InetAddress::InetAddress(const std::string& ip, uint16_t port)
{
	bzero(&m_addr, sizeof m_addr);
	sockets::fromHostPort(ip.c_str(), port, &m_addr);
}

std::string InetAddress::toHostPort()const
{
	char buf[32];
	sockets::toHostPort(buf, sizeof buf, m_addr);
	return buf;
}