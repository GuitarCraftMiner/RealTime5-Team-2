#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <softPWM.h>
#include "genVoltage.h"

//Adafruit_ADS1015 ads;
genVoltage gV;
int input;


int main(int argc, char *argv[]){
  
  // Obtain Reading
  input = gV.getReading();
  gV.getVoltage(input);
  
  // PWM setup
  /*wiringPiSetup();
  pinMode(1, OUTPUT);

  softPwmCreate(1,0,100);
  softPwmWrite(1,10);
  delay(5000);
  softPwmWrite(1,0);
  delay(5000);
  softPwmWrite(1,100);
  delay(5000);
  softPwmWrite(1,0);

  for(;;){
    
    for (l=0;l<1024;++l){
    pwmWrite(1,l);
    delay(1);
    }
    
    for (l=0;l<1024;--l){
    pwmWrite(1,l);
    delay(1);
    }
  }

  return 0;*/
}


