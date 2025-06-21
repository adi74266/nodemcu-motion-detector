#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "wifi_handler.h"
#include "oled_handler.h"
#include "web_server.h"
#include "sensors.h"

void setup(){
  Serial.begin(115200);
  init_pins();
  init_OLED();
  connect_to_WiFi();
  setup_WebServer();
}
void loop(){
  server.handleClient();
  Update_Sensors();
}