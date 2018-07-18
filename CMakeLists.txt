PROJECT (MYSERVER)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O0 -Wno-unused-variable -pthread")

SET(net_srcs 
base/timestamp.cpp
base/logging.cpp
base/logstream.cpp
s07/Buffer.cc
s07/EventLoop.cc
s07/Channel.cc
s07/Poller.cc
s07/Timer.cc
s07/TimerQueue.cc
s07/EventLoopThread.cc
s07/SocketsOps.cc
s07/InetAddress.cc
s07/Socket.cc
s07/Acceptor.cc
s07/TcpConnection.cc
s07/TcpServer.cc
s07/test8.cc
)

MESSAGE(STATUS "This is BINARY dir" ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir" ${PROJECT_SOURCE_DIR})
ADD_EXECUTABLE(log ${net_srcs})