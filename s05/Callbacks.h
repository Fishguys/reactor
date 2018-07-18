#ifndef NET_CALLBACKS_H
#define NET_CALLBACKS_H

#include <functional>
#include <memory>

#include "../base/timestamp.h"

// All client visible callbacks go here.
class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

typedef std::function<void()> TimerCallback;
typedef std::function<void (const TcpConnectionPtr)> ConnectionCallback;
typedef std::function<void (const TcpConnectionPtr&,
                              const char* data,
                              ssize_t len)> MessageCallback;
#endif  //NET_CALLBACKS_H
