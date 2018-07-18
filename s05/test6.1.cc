/**********************test case for 8.3.1******************/
#include "EventLoop.h"
#include "../base/logging.h"

#include <functional>
#include <iostream>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>

EventLoop* g_loop;
int g_flag = 0;

void print(){
	std::cout << "print thread id: " << std::this_thread::get_id() << std::endl;
}

void threadFunc()
{
	std::cout << "threadFunc thread id: " << std::this_thread::get_id() << std::endl;
	g_loop->runAfter(1.0, print);
	g_loop->quit();
}

int main()
{
	std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
	Logger::setLogLevel(Logger::TRACE);

	EventLoop loop;
	g_loop = &loop;

	std::thread foo(threadFunc);
	loop.loop();
	foo.join();
	printf("main loop exits");
}