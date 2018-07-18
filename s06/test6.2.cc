/**********************test case for 8.3.2******************/
#include "EventLoop.h"
#include "../base/logging.h"
#include "EventLoopThread.h"

#include <functional>
#include <iostream>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

void runInThread()
{
	std::cout << "runInThread() ThreadId: " << std::this_thread::get_id() << std::endl;
}
int main()
{
	std::cout << "main() ThreadId: " << std::this_thread::get_id() << std::endl;
	Logger::setLogLevel(Logger::TRACE);

	EventLoopThread loopThread;
	EventLoop* loop = loopThread.startLoop();
	loop->runInLoop(runInThread);
	
	sleep(1);
	
	loop->runAfter(2, runInThread);
	sleep(3);


	printf("exit main().\n");
}