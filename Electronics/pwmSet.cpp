#include "pwmSet.h"

#include <stdio.h>
#include <chrono>
#include <thread>
#include <wiringPi.h>

int servo = 1;	//PWM pin

void pwmSet::run() {
	// Set Servo PWM
	pwmWrite(servo, new_pwm);
}

