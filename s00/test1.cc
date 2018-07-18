#include "EventLoop.h"
#include "../base/logging.h"
#include <thread>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	Logger::setLogLevel(Logger::TRACE);
	LOG_TRACE << "Test TRACE!";
}
