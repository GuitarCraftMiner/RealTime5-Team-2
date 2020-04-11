# Software for System
C++ System Software for Controlling the Blade Pitch of the Wind Turbine

!!! A detailed description can be found at the wiki !!!

https://github.com/GuitarCraftMiner/RealTime5-Team-2/wiki/Software

## Running the Program
To run the program ```main,cpp```, direct to the Software folder and type ```cmake .```, ```make``` and then ```sudo ./main```.
```sudo```is required due to generate PWM

## Running Tests
There are two unit tests available:
- Obtain generated voltage readings ```genVoltage.cpp```
- Generate PWM for blade pitch angle control ```pwmSet.cpp```

To run the program, direct to the test folder and which unit test to run then type ```cmake .```, ```make``` and then ```sudo ./<name_of_program>```.
```sudo```is required due to generate PWM




