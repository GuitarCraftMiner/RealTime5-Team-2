#include "pwmSet.h"

#include <stdio.h>
#include <wiringPi.h>

int servo = 1;	//PWM pin
int pwm;
pwmSet pS;

void pwmSet::setpwm(int new_pwm) {
	// Set Servo PWM
	pwmWrite(servo, new_pwm);
}

int main(int argc, char *argv[]){
	// Initialising wiringPi in wiringPi numbering scheme
	wiringPiSetup();
	// PWM setup
	pinMode(servo, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(192);
	pwmSetRange(2000);
	
	while (true){
		for (pwm=50; pwm<=110; pwm++){
			pS.setpwm(pwm);
			delay(100);
		}
		for (pwm=110; pwm>=50; pwm--){
			pS.setpwm(pwm);
			delay(100);
		}
	}
}
