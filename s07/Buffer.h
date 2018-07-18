#ifndef NET_BUFFER_H
#define NET_BUFFER_H

#include <algorithm>
#include <string>
#include <vector>

#include <assert.h>

/// A buffer class modeled after org.jboss.netty.buffer.ChannelBuffer
///
/// @code
/// +-------------------+------------------+------------------+
/// | prependable bytes |  readable bytes  |  writable bytes  |
/// |                   |     (CONTENT)    |                  |
/// +-------------------+------------------+------------------+
/// |                   |                  |                  |
/// 0      <=      readerIndex   <=   writerIndex    <=     size
/// @endcode

class Buffer
{
public:
	static const size_t kCheapPrepend = 8;
	static const size_t kInitialSize = 1024;
	
	Buffer() :
		m_vecBuffer(kCheapPrepend + kInitialSize),
		m_readerIndex(kCheapPrepend),
		m_writerIndex(kCheapPrepend)
	{
	
	}
private:
	std::vector<char> m_vecBuffer;
	size_t m_readerIndex;
	size_t m_writerIndex;
};
#endif //NET_BUFFER_H