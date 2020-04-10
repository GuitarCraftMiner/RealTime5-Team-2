#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include "genVoltage.h"
#include "pwmSet.h"

// Initialise Variables
genVoltage gV;
int input;
int Vgen;


int main(int argc, char *argv[]){
  // Run the System
  while (true){
    gV.start();
    gV.join();
  }
}


