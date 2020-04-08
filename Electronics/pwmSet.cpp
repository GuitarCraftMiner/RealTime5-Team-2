#include "pwmSet.h"

#include <stdio.h>
#include <chrono>
#include <thread>
#include <wiringPi.h>

int servo = 1;	//PWM pin

void pwmSet::run() {
	// Initialising wiringPi in wiringPi numbering scheme
	wiringPiSetup();
	// PWM setup
	pinMode(servo, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(192);
	pwmSetRange(2000);
	
	printf("PWM at 50\n");
	pwmWrite(servo,50);
	delay(5000);
	printf("PWM at 80\n");
	pwmWrite(servo,80);
	delay(5000);
	printf("PWM at 110\n");
	pwmWrite(servo,110);
	delay(5000);
	printf("PWM at 80\n");
	pwmWrite(servo,80);
	delay(5000);
	printf("PWM at 50\n");
	pwmWrite(servo,50);
	delay(5000);
}

