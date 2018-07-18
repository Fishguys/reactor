#include "Channel.h"
#include "EventLoop.h"
#include "../base/logging.h"

#include <poll.h>

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = POLLIN | POLLPRI;
const int Channel::kWriteEvent = POLLOUT;

Channel::Channel(EventLoop* loop, int fdArg)
  : loop_(loop),
    fd_(fdArg),
    events_(0),
    revents_(0),
    index_(-1),
	eventHandling_(false)
{
}

Channel::~Channel()
{
	//防止出现Channel对象已经析构的情况下调用handleEvent()
	assert(!eventHandling_);
}

void Channel::update()
{
	loop_->updateChannel(this);
}

void Channel::handleEvent()
{
	eventHandling_ = true;
	if (revents_ & POLLNVAL)		//文件描述符没有打开
	{
		LOG_WARN << "Channel::handle_event() POLLNVAL";
	}

	if ((revents_ & POLLHUP) && !(revents_ & POLLIN))
	{
		LOG_WARN << "Channel::handle_event() POLLHUP";
		if (closeCallback_) closeCallback_();
	}

	if (revents_ & (POLLERR | POLLNVAL))	//错误
	{
		if (errorCallback_) errorCallback_();
	}
	//POLLRDHUP它在socket上接收到对方关闭连接的请求之后触发。使用此事件需要在代码最开始处定义_GNU_SOURCE
	if (revents_ & (POLLIN | POLLPRI | POLLRDHUP))
	{
		if (readCallback_) readCallback_();
	}
	
	if (revents_ & POLLOUT)
	{
		if (writeCallback_) writeCallback_();
	}
	eventHandling_ = false;
}
