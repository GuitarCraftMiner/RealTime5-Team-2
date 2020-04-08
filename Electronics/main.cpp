#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include "genVoltage.h"
#include "pwmSet.h"

genVoltage gV;
int input;
int Vgen;


int main(int argc, char *argv[]){
  while (true){
    gV.start();
    gV.join();
  }
}


