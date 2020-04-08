#include "DemoThread.h"

#include <stdio.h>
#include <chrono>
#include <thread>
#include <wiringPi.h>

void DemoThread::run() {
	for(int i=0;i<10;i++) {
		printf("%d\n",i+offset);
		delay(1000);
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
