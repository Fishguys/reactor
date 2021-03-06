#ifndef NET_SOCKETSOPS_H
#define NET_SOCKETSOPS_H

#include <arpa/inet.h>
#include <endian.h>

namespace sockets
{
	
inline uint64_t hostToNetWork64(uint64_t host64)
{
	return htobe64(host64);   //host to bigest endian
}

inline uint32_t hostToNetWork32(uint32_t host32)
{
	return htonl(host32);
}

inline uint16_t hostToNetWork16(uint16_t host16)
{
	return htons(host16);
}

inline uint64_t networkToHost64(uint64_t net64)
{
  return be64toh(net64);
}

inline uint32_t networkToHost32(uint32_t net32)
{
  return ntohl(net32);
}

inline uint16_t networkToHost16(uint16_t net16)
{
  return ntohs(net16);
}

//Create a non_blocking socket fiel descriptor,
//abort if error.
int createNonblockingOrDie();

void bindOrDie(int sockfd, const struct sockaddr_in& addr);
void listenOrDie(int sockfd);
int accept(int sockfd, struct sockaddr_in* addr);
void close(int sockfd);

void toHostPort(char* buf, size_t size,
				const struct sockaddr_in& addr);
void fromHostPort(const char* ip, uint16_t port,
				struct sockaddr_in* addr);
}
#endif //NET_SOCKETSOPS_H