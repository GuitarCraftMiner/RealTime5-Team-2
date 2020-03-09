#include <stdio.h>
#include <wiringPi.h>


int main(){
	printf("Start\n");
	// Initialise WiringPi using wiringPi's simplified number system
	wiringPiSetup(); 
	printf("Initialise WiringPI\n");
	// Declare pins
	pinMode(12, OUTPUT);
	printf("Declare pin\n");
	
	while(1) {
		digitalWrite(25, HIGH);
		printf("ON\n");
		delay(5000);
		digitalWrite(25, LOW);
		printf("OFF\n");
		delay(5000);
	}
	return 0;
}
