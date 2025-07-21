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
### PIR Motion Sensor
This component is responsible for the detecting motion and send the detected signal to the processor. It has VCC and GND pin for power and a Digital Out Pin for sending the detected signal back. 
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