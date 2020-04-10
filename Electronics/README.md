# Electronic Design for System

## Block Diagram
Analog output signal from the generator is fed into an Analog-to-Digital-Converter (ADC) as the Raspberry Pi does not include a hardware ADC. Hence, an external ADC is required. The ADC (ADS1015) is a 12-bit ADC that uses I2C communication protocol to read analog values. Depending on the Voltage readings obtained from the generator, a Pulse-Width-Modulation (PWM) control signal is sent to the servo motor which controls the blade pitch. This is done to keep the generator within operating limits.
![Electronics Block Diagram](https://github.com/GuitarCraftMiner/RealTime5-Team-2/blob/master/images/Electronics_BD.png)

## Schematic Diagram


## ADC circuit
The specifications of ADS1015 which has been chosen to convert signal will be provided in the table 1, 

Table 1: Specifications of ADS1015 and the recommendded operating conditions
|Feature|Pins|Min/Reccommendded|Max/Reccommendded|Unit|
|:---|:---|:---:|:---:|:---:|
|Power-supply voltage|VDD to GND|-3 / 2|7 / 5.5|V|
|Analog input voltage|AIN0,AIN1,AIN2,AIN3|GND-0.3 / ±0.256|VDD+0.3 / ±6.144|V|
|Digital input voltage|SDA,SCL,ADDR,ALERT/RDY|GND-0.3 / GND|5.5 / 5.5|V|
|Input current, continuous|Any pin ecept power supply pins|-10|10|mA|

*Adapted from TEXA INSTRUMENTS*
