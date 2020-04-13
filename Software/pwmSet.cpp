#include "pwmSet.h"

#include <stdio.h>
#include <chrono>
#include <thread>
#include <wiringPi.h>

int current_pwm = 75; // Set Blade Pitch at best angle
float Kp = 1.5; // Controller Gain

int servo = 1;	//PWM pin

void pwmSet::run() {
	// Calculate New PWM
	new_pwm = current_pwm - (Kp*error);
	
	// Limit PWM Range
	if (new_pwm < 75){
		new_pwm = 75;
	}
	if (new_pwm > 110){
		new_pwm = 110;
	}
	// Update PWM Reading
	current_pwm = new_pwm;
	
	// Set Servo PWM
	pwmWrite(servo, new_pwm);
}

