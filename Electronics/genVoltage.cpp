#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "Adafruit_ADS1015.h"
#include <wiringPiI2C.h>
#include "genVoltage.h"

Adafruit_ADS1015 ads;
float min_good_voltage = 10;
float max_good_voltage = 15;

void checkRange(float v_in){
	if (v_in > min_good_voltage & v_in < max_good_voltage){
		printf("Good\n");
	}
	
	if (v_in < min_good_voltage){
		printf("Low\n");
	}
	
	if (v_in > max_good_voltage){
		printf("High\n");
	}
}

void genVoltage::run(){
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
		float voltage_mV = voltage * 1000;	// Voltage in mV
		usleep(1000000); //1s Sampling Time
		printf("Generated Voltage: \t %.4f\t mv \n", voltage_mV);
		
		checkRange(voltage_mV);
	}
}
