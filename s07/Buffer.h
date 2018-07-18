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
		assert(readableBytes() == 0);
		assert(writeableBytes() == kInitialSize);
		assert(prependableBytes() == kCheapPrepend);
	}

	size_t readableBytes()const
	{
		return m_writerIndex - m_readerIndex;
	}

	size_t writeableBytes()const
	{
		return m_vecBuffer.size() - m_writerIndex;
	}

	size_t prependableBytes()const
	{
		return m_readerIndex;
	}

	const char* peek()const
	{
		return begin() + m_readerIndex;
	}

	char* beginWrite()
	{
		return begin() + m_writerIndex;
	}

	const char* beginWrite() const
	{
		return begin() + m_writerIndex;
	}

	void hasWritten(size_t len)
	{
		m_writerIndex += len;
	}

	// retrieve returns void, to prevent
	// string str(retrieve(readableBytes()), readableBytes());
	// the evaluation of two functions are unspecified
	void retrieve(size_t len)
	{
		assert(len <= readableBytes());
		m_readerIndex += len;
	}
	//ÐÞ¸Äm_readerIndexµ½end
	void retrieveUntil(const char* end)
	{
		assert(peek() <= end);
		assert(end <= beginWrite());
		retrieve(end - peek());
	}

	void retrieveAll()
	{
		m_readerIndex = kCheapPrepend;
		m_writerIndex = kCheapPrepend;
	}

	std::string retrieveAsString()
	{
		std::string str(peek(), readableBytes());
		retrieveAll();
		return str;
	}

	void append(const char* /*restrict*/ data, size_t len)
	{
		ensureWritableBytes(len);
		std::copy(data, data + len, beginWrite());
		hasWritten(len);
	}

	void append(const void* /*restrict*/ data, size_t len)
	{
		append(static_cast<const char*>(data), len);
	}

	void ensureWritableBytes(size_t len)
	{
		if (writeableBytes() < len)
		{
			makeSpace(len);
		}
		assert(writeableBytes() >= len);
	}
	
	void prepend(const void* /*restrict*/ data, size_t len)
	{
		assert(len <= prependableBytes());
		m_readerIndex -= len;
		const char* d = static_cast<const char*>(data);
		std::copy(d, d + len, begin() + m_readerIndex);
	}

	void shrink(size_t reserve)
	{
		// move readable data to the buf front, then swap with m_vecBuffer
		std::vector<char> buf(kCheapPrepend + readableBytes() + reserve);
		std::copy(peek(), peek() + readableBytes(), buf.begin() + kCheapPrepend);
		buf.swap(m_vecBuffer);
	}

	/// Read data directly into buffer.
	///
	/// It may implement with readv(2)
	/// @return result of read(2), @c errno is saved
	ssize_t readFd(int fd, int* savedErrno);
private:
	char* begin()
	{
		return &*m_vecBuffer.begin();
	}

	const char* begin()const
	{
		return &*m_vecBuffer.begin();
	}

	void makeSpace(size_t len)
	{
		if (prependableBytes() + writeableBytes() < len + kCheapPrepend){
			m_vecBuffer.resize(m_writerIndex + len);
		}
		else
		{
			// move readable data to the front, make space inside buffer
			assert(kCheapPrepend < m_readerIndex);
			size_t readable = readableBytes();
			std::copy(begin() + m_readerIndex,
				begin() + m_writerIndex,
				begin() + kCheapPrepend);
			m_readerIndex = kCheapPrepend;
			m_writerIndex = m_readerIndex + readable;
			assert(readable == readableBytes());
		}
	}
	std::vector<char> m_vecBuffer;
	size_t m_readerIndex;
	size_t m_writerIndex;
};
#endif //NET_BUFFER_H