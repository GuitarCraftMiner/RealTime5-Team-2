#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <time.h>

#include "Adafruit_ADS1015.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "genVoltage.h"
#include "pwmSet.h"

// Initialise Variables
Adafruit_ADS1015 ads;
float desired_voltage = 10;
float actual_voltage = 0;
float old_voltage = 0;
float error;
float Kp = 1.5; // Controller Gain
int current_pwm = 75; // Set Blade Pitch at best angle
int new_pwm;
int pwm;

/* PROPORTIONAL CONTROLLER FOR BLADE PITCH
 * Controller calulates the error between the actual and desired voltage
 * and generates new pwm according to the error
 */
int controller(){
	error = desired_voltage - actual_voltage;
	
	if (abs(error) >= 1){
		new_pwm = current_pwm - (Kp*error);
		// Limit PWM Range
		if (new_pwm < 75){
			new_pwm = 75;
		}
		if (new_pwm > 110){
			new_pwm = 110;
		}
		
		current_pwm = new_pwm;
		pwmSet pS(new_pwm);
		
		pS.start();
		pS.join();
	}
	return new_pwm;
}

/* THREADS TO GENERATED VOLTAGE READINGS AND RUN THE CONTROLLER 
 * Code includes inital setups for PWM and ADC, and Real-Time CSV DATA LOG
 */
void genVoltage::run(){
	// INITIAL SETUP
	printf("Initial Setting... \n");
	// Initialising wiringPi in wiringPi numbering scheme
	wiringPiSetup();
	// PWM setup
	pinMode(1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(192);
	pwmSetRange(2000);
	printf("Generated Voltage: \t %.4f mv \n", actual_voltage);
	printf("PWM at %i\n", current_pwm);
	printf("----------------------------\n");
	pwmWrite(1, current_pwm);
	// ADC Setup
	// Define Voltage Range to read to +/-4.096V
	ads.setGain(GAIN_ONE);
	// Begin reading
	ads.begin();
	
	// CSV DATA LOG
	FILE *fp;
	fp = fopen("Data_Log.csv","w");
	fprintf(fp, "Time,Voltage,PWM\n");
	fclose(fp);
	clock_t start = clock();
	
	// MAIN PROCESS
	while (true){
		fp = fopen("Data_Log.csv","a");
		uint16_t adc0 = ads.readADC_SingleEnded(0);
		int input = int(adc0);
		
		// Data Conversion
		float conversion = 3.3 / 4096;	// Conversion value
		float voltage = input * conversion;	// Voltage in V
		actual_voltage = voltage * 1000;	// Voltage in mV
		
		// Filter maxed out readings
		if (actual_voltage >= 3290){
			actual_voltage = old_voltage;
		}
		
		usleep(10000); //100Hz Sampling Time
		
		// Run controller
		pwm = controller();
		
		// Print to Terminal if there is change in Generated Voltage
		if (error != 10){
			printf("Generated Voltage: \t %.4f mv \n", actual_voltage);
			printf("PWM at %i\n", pwm);
		}
		
		old_voltage = actual_voltage;
		
		// CSV Data Clock
		clock_t stop = clock();
		double diff = (double)(stop-start)*1000/CLOCKS_PER_SEC;
		
		// Print to csv file
		fprintf(fp, "%f,%f,%i\n", diff, actual_voltage, pwm);
		fclose(fp);
	}
}
