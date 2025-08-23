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
### Passive Infrared (PIR) Sensor (HC-SR501)
This component detects the  motion by sending and receiving the changes detected on its sensor. A plastic dome is present to concentrate the input infrared to a single point. There are 3 pins and 2 potentiometer available on this component. There is VCC and GND pin and an OUT pin for sending output. THe potentiometers in this component are used to adjust the detection distance and the delay in sending individual output from the component to the main circuit board.
### Light Dependent Resistor (LDR)
This component is used to detect the daynight cycle for the operation of the whole project. It changes its resistance based on the input light received. It has to be set up in a voltage divider circuit. Photodiode can be used as replacement.
### I2C OLED Display
This component in this circuit, will act as an output screen that shows if the circuit is active, how much light is being sent to the processor and whether the motion is detected or not. The screen has individual pixels which are either turned ON or OFF which shows the required Output.
### Light Emitting Diode (LED)
A basic LED which will show when a movement is detected by the Motion Sensor.





