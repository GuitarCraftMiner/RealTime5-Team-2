#include <stdio.h>
#include <unistd.h>

#include "Adafruit_ADS1015.h"
#include <wiringPiI2C.h>

int main(int argc, char *argv[])
{
  uint16_t adc0;
  float conversion, voltage;

  ads.setGain(GAIN_ONE);
  ads.begin();
  while (true) {
    adc0 = ads.readADC_SingleEnded(0);
    conversion = 3.3/4096;
    voltage = int(adc0)*conversion;
    printf("%f\n", voltage);
    usleep(100000);
  }
}
