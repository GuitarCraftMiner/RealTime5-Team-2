# Software for System
C++ System Software for Controlling the Blade Pitch of the Wind Turbine

!!! A detailed description can be found at the wiki !!!

https://github.com/GuitarCraftMiner/RealTime5-Team-2/wiki/Software

## Pre-Requisites
1. Enable Raspberry Pi's I2C interfaces
```
sudo raspi-config
# then go to "Interfacing Options and enable I2C
```
2. Install wiring Pi: http://wiringpi.com/download-and-install/
```
sudo apt-get install wiringpi
```
3. Install the ADS1015 C++ Library: https://github.com/hallgrimur1471/Adafruit_ADS1X15_RPi

## Running the Program
To run the program ```main,cpp```, direct to the Software folder and type ```cmake .```, ```make``` and then ```sudo ./main```.
```sudo```is required due to generate PWM

## Running Tests
There are two unit tests available:
- Obtain generated voltage readings ```genVoltage.cpp```
- Generate PWM for blade pitch angle control ```pwmSet.cpp```

To run the program, direct to the test folder and which unit test to run then type ```cmake .```, ```make``` and then ```sudo ./<name_of_program>```.
```sudo```is required due to generate PWM




