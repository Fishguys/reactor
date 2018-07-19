#ifndef NET_CALLBACKS_H
#define NET_CALLBACKS_H

#include <functional>
#include <memory>

#include "../base/timestamp.h"

// All client visible callbacks go here.
class TcpConnection;
class Buffer;

typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

typedef std::function<void()> TimerCallback;
typedef std::function<void (const TcpConnectionPtr)> ConnectionCallback;
typedef std::function<void (const TcpConnectionPtr&,
                              Buffer* buf,
                              Timestamp)> MessageCallback;
typedef std::function<void(const TcpConnectionPtr&)> CloseCallback;
#endif  //NET_CALLBACKS_H
