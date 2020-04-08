#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "Adafruit_ADS1015.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "genVoltage.h"
#include "pwmSet.h"

Adafruit_ADS1015 ads;
float desired_voltage = 10;
float actual_voltage;
float error;
float Kp = 1.5;
int current_pwm = 75; // Set Blade Pitch at best angle
int new_pwm;


void controller(){
	error = desired_voltage - actual_voltage;
	if (abs(error) >= 0.001){
		new_pwm = current_pwm - (Kp*error);
		// Limit PWM Range
		if (new_pwm < 75){
			new_pwm = 75;
		}
		if (new_pwm > 110){
			new_pwm = 110;
		}
		//printf("New PWM: %i \t Current PWM %i \n", new_pwm, current_pwm);
		current_pwm = new_pwm;
		pwmSet pS(new_pwm);
		pS.start();
		pS.join();
		//printf("New PWM: %i \t Current PWM %i \n", new_pwm, current_pwm);
	}
}

void genVoltage::run(){
	// Initial Setup
	printf("Initial Setting... \n");
	// Initialising wiringPi in wiringPi numbering scheme
	wiringPiSetup();
	// PWM setup
	pinMode(1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(192);
	pwmSetRange(2000);
	printf("PWM at %i\n", current_pwm);
	printf("----------------------------\n");
	pwmWrite(1, current_pwm);
	
	while (true){
		// Define Voltage Range to read to +/-4.096V
		ads.setGain(GAIN_ONE);
		// Begin reading
		ads.begin();
		uint16_t adc0 = ads.readADC_SingleEnded(0);
		int input = int(adc0);
		//Conversion Process
		float conversion = 3.3 / 4096;	// Conversion value
		float voltage = input * conversion;	// Voltage in V
		actual_voltage = voltage * 1000;	// Voltage in mV
		usleep(100000); //10Hz Sampling Time
		printf("Generated Voltage: \t %.4f mv \n", actual_voltage);
		
		// Run controller
		controller();
	}
}
