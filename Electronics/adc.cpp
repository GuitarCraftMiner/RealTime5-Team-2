#include <stdio.h>
#include <unistd.h>
#include <cmath>

#include "Adafruit_ADS1015.h"
#include <wiringPiI2C.h>

// CLASS FOR CONVERTING ANALOG INPUT ADC VALUES TO VOLTAGE (NOT WORKING)

Adafruit_ADS1015 ads;

//Convert Two's complement to Hex
char convert(size_t const size, void const * const ptr)
{
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j, hex;
  
  // Conversion to Binary
  for (i=size-1;i>=0;i--) {
    for (j=7;j>=0;j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  
  // Conversion to Hex
  
  
  return hex;
}


int main(int argc, char *argv[])
{
  uint16_t adc0;
  int hex, dec, vol;

  ads.setGain(GAIN_ONE);
  ads.begin();
  while (true) {
    adc0 = ads.readADC_SingleEnded(0);
    hex = convert(sizeof(adc0), &adc0);
    dec = hex % 10;
    vol = dec*3300/4096;
    printf(" *** %d\n", vol);
    usleep(100000);
  }
}
