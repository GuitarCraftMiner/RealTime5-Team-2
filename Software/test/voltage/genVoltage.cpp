#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <time.h>

#include "Adafruit_ADS1015.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "genVoltage.h"

// Initialise Variables
genVoltage gV;
Adafruit_ADS1015 ads;
float actual_voltage = 0;
float old_voltage = 0;

void genVoltage::run(){
	// ADC Setup
	// Define Voltage Range to read to +/-4.096V
	ads.setGain(GAIN_ONE);
	// Begin reading
	ads.begin();
	
	// MAIN PROCESS
	while (true){
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
		
		printf("Generated Voltage: \t %.4f mV \n", actual_voltage);
		
		old_voltage = actual_voltage;
		
		usleep(10000); //100Hz Sampling Time
	}
}

int main(int argc, char *argv[]){
  while (true){
    gV.start();
    gV.join();
  }
}
