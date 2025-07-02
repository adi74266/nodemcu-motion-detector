#ifndef SENSORS_H
#define SENSORS_H

extern Adafruit_SSD1306 display;
extern ESP8266WebServer server;

const char* ssid="";
const char* password="";

const int pir_Pin=D5;
const int ldr_Pin=A0;
const int LedPin=D0;

const int lightThreshold=250;

bool browserControl=true;

void init_pins(){
  pinMode(pir_Pin,INPUT);
  pinMode(LedPin,OUTPUT);
}
void Update_Sensors(){
  int ldr_Val=analogRead(ldr_Pin);
  bool motion=digitalRead(pir_Pin);
  bool enabled=browserControl;

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("System: ");
  display.println(enabled?"ON":"OFF");
  display.print("Light State: ");
  display.println(ldr_Val);
  display.print("Mode: ");
  display.println((ldr_Val<lightThreshold)? "Night": "Day");

  if (enabled&& ldr_Val<lightThreshold){
    if (motion){
      display.setCursor(0,40);
      display.println("Motion Detected!");
      digitalWrite(LedPin,HIGH);
      } else{
        display.setCursor(0,40);
        display.println("No Motion Detected");
        digitalWrite(LedPin,LOW);
      }
      display.display();
      delay(200);
  }
}
#endif