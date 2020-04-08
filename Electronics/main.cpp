#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include <wiringPi.h>
#include "genVoltage.h"
#include "pwmSet.h"

genVoltage gV;
int input;
int Vgen;
pwmSet pS;


int main(int argc, char *argv[]){
  while (true){
    pS.start();
    gV.start();
    pS.join();
    gV.join();
    // Obtain Reading
    //input = gV.getReading();
    //printf("Input Reading: \t%i\n", input);
    //Vgen = gV.getVoltage(input);
    //printf("Generated Voltage: \t%i mV\n", Vgen);
  }
}


