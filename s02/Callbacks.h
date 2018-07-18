#ifndef NET_CALLBACKS_H
#define NET_CALLBACKS_H

#include <functional>
#include <memory>

#include "../base/timestamp.h"

// All client visible callbacks go here.

typedef std::function<void()> TimerCallback;

#endif  //NET_CALLBACKS_H
