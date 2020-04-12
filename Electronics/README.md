# Electronic Design for System

!!! A detailed description can be found at the wiki !!!

https://github.com/GuitarCraftMiner/RealTime5-Team-2/wiki/Electronics

## Block Diagram
Analog output signal from the generator is fed into an Analog-to-Digital-Converter (ADC) as the Raspberry Pi does not include a hardware ADC. Hence, an external ADC is required. The ADC (ADS1015) is a 12-bit ADC that uses I2C communication protocol to read analog values. Depending on the Voltage readings obtained from the generator, a Pulse-Width-Modulation (PWM) control signal is sent to the servo motor which controls the blade pitch. This is done to keep the generator within operating limits.
![Electronics Block Diagram](https://github.com/GuitarCraftMiner/RealTime5-Team-2/blob/master/images/Electronics_BD.png)

