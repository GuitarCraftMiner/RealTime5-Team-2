#include <stdio.h>
#include <unistd.h>

#include "Adafruit_ADS1015.h"
#include "genVoltage.h"

Adafruit_ADS1015 ads;

int genVoltage::getReading(){

	// CODE WITH REAL HARDWARE
	/*
	// Define Voltage Range to read to +/-4.096V
	ads.setGain(GAIN_ONE);
	// Begin reading
	ads.begin();
	while (true){
		uint16_t adc0 = ads.readADC_SingleEnded(0);
		usleep(5000000); //5s Sampling Time
	*/

	// CODE WITH SIMULATED HARDWARE READINGS
	uint16_t adc0 = 1911;
	int input = int(adc0);

	return input;
}

int genVoltage::getVoltage(int input){
	float voltagemV;
	
	// Conversion value
	float conversion = 3.3 / 4096;
	
	// Voltage in V
	float voltage = input * conversion;
	
	// Voltage in mV
	voltagemV = voltage * 1000;
	printf("%f\n", voltagemV);
	
	// Take reading at 10Hz (every 0.1s)
	//usleep(100000); 
	
	return voltagemV;
}
