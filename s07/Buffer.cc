#include "Buffer.h"
#include "SocketsOps.h"
#include "../base/logging.h"

#include <errno.h>
#include <memory.h>
#include <sys/uio.h>	//readv

ssize_t Buffer::readFd(int fd, int* savedErrno)
{
	char extrabuf[65536];
	struct iovec vec[2];
	const size_t writable = writeableBytes();
	vec[0].iov_base = beginWrite();
	vec[0].iov_len = writeableBytes();
	vec[1].iov_base = extrabuf;
	vec[1].iov_len = sizeof extrabuf;
	const ssize_t n = ::readv(fd, vec, 2);
	if (n < 0){
		*savedErrno = errno;
		LOG_ERROR << "Buffer::readFd errno = " << errno;
	}
	else if (static_cast<size_t>(n) <= writable){
		m_writerIndex += n;
	}
	else{
		m_writerIndex = m_vecBuffer.size();
		append(extrabuf, n - writable);
	}
	return n;
}