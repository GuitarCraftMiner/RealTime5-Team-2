# Mechanical Design of Wind Turbine

## Assembly
* All parts separately as .IPT
* Assemblies as .IAM

## Generator
* .IPT Autodesk drawing
* .STP Generic Step file

## Parts links

### 4mm Ball Bearings
Link: https://uk.rs-online.com/web/p/ball-bearings/6189890/
### 10mm Ball Bearings
Link: https://uk.rs-online.com/web/p/ball-bearings/6189979/

# Detailed Description of Design

The model was designed using Autodesk Fusion 360 to be accessible for everyone to download and work with as Fusion 360 is available for free for hobbyists to use. It is also widely supported online and plenty of guides are available to allow for the model parts to be manufactured using almost any method.

## Rotor

![Rotor Drawing](https://github.com/GuitarCraftMiner/RealTime5-Team-2/blob/master/images/Rotor_Diagram.png)

The main idea behing this design was to follow the way helicopter blade pitch mechanisms are designed and implement it in the wind turbine model at a smaller scale and using simple off-the-shelf or easy to make components.

The most crucial reguirement for the rotor is that it must be able to adjust the pitch while still for the rotation of the blades. In helicopters, this is solved by using a swash plate, which is essentially a bearings, poth parts of which are independent from the main rotor shaft. One part rotates at the same speed as the shaft, but crucially, can slide along it to adjust pitch. The other part does not rotate with respect to the main helicopted body and is connected to the servos that actuate the pitch mechanism. This is a requirement as there would be no sensible way to have the servos rotate with the blades.

![Mechaninsm Explained](https://github.com/GuitarCraftMiner/RealTime5-Team-2/blob/master/images/Mechanism_explain.png)

