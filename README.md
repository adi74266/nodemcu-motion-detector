# NodeMCU Motion Detector
## Introduction
This is a circuit based project where the motion is sensed and shown on an LED. <br>
In this project there are these components involved:
- ESP8266 NodeMCU
- PIR Motion Sensor (HC-SR501)
- Photoresistor (Light Dependent Resistor or LDR)
- I2C OLED Display (0.96", SSD1306) 
- Light Emitting Diode (LED)
- Breadboard
- Jumper Wires
- Micro USB Cable
---
## Component Details
### ESP8266 NodeMCU
This component is the main processor for this device. It is a 30-pin board which has several GPIO pins, few 3.3 volt VCC pins and few GND pins.<br> 
![This is the image of NodeMCU]("https://github.com/adi74266/nodemcu-motion-detector/main/assets/NodeMCU.jpg")
![NodeMCU](https://github.com/user-attachments/assets/dc09b834-10a6-4c85-9fe5-1a5a76992fa4)
The above image is the market available circuit board.
![nodemcudevkit_v1-0_io-4280715523](https://github.com/user-attachments/assets/d02656a8-28ca-44c6-9c8e-af4447fd2f3e)
This is the visual representation of the pin names and their uses.
### Passive Infrared (PIR) Sensor (HC-SR501)
This component detects the  motion by sending and receiving the changes detected on its sensor. A plastic dome is present to concentrate the input infrared to a single point. There are 3 pins and 2 potentiometer available on this component. There is VCC and GND pin and an OUT pin for sending output. THe potentiometers in this component are used to adjust the detection distance and the delay in sending individual output from the component to the main circuit board.
![HC-SR501-Pyroelectric-Infrared-Motion-Sensor-PIR-1-2999069279](https://github.com/user-attachments/assets/2d616036-8537-45bd-bc9e-c13e372b00d0)
### Light Dependent Resistor (LDR)
This component is used to detect the daynight cycle for the operation of the whole project. It changes its resistance based on the input light received. It has to be set up in a voltage divider circuit.
- For its replacement, a photodiode can also be used in case of unavailability.
### Photoresistor
This component is based on the principle that when the light falls on it, it changes its resistance according to the amount of light. There is also Photodiode available in the market that works similar to the it but has a difference that it is bidirectional. The signal sent by it is Analog Signal so the input should be in Analog Pin.
### I2C OLED Display
This component in this circuit, will act as an output screen that shows if the circuit is active, how much light is being sent to the processor and whether the motion is detected or not. The screen has individual pixels which are either turned ON or OFF which shows the required Output.
### Light Emitting Diode (LED)
A basic LED which will show when a movement is detected by the Motion Sensor.
### Breadboard
It is the board where the circuit is prototyped and tested before being soldering to a Copper Clad PCB board.
### Jumper Wires
It is used for prototyping and testing circuits. There are 3 types of jumper wires i.e., Male to Male, Female to Male and Female to Female.
### 

