#ifndef NET_SOCKET_H
#define NET_SOCKET_H
class InetAddress;

// Wrapper of socket file descriptor.

// It closes the sockfd when desctructs.
// It's thread safe, all operations are delagated to OS.
class Socket
{
public:
	explicit Socket(int sockfd)
		: m_sockfd(sockfd)
		{}
	~Socket();
	
	int fd() const{ return m_sockfd;}
	
	//abort if address in use
	void bindAddress(const InetAddress& localaddr);
	//abort if address in use
	void listen();
	
	// On success, returns a non-negative integer that is
	// a descriptor for the accepted socket, which has been
	// set to non-blocking and close-on-exec. *peeraddr is assigned.
	// On error, -1 is returned, and *peeraddr is untouched.
	int accept(InetAddress* peeraddr);
	
	// Enable/disable SO_REUSEADDR
	void setReuseAddr(bool on);
private:
	const int m_sockfd;
};
#endif //NET_SOCKET_H