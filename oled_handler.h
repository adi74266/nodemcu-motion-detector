// This file handles the LED display part.

#ifndef OLED_HANDLER_H
#define OLED_HANDLER_H

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define oled_SDA_Pin D3
#define oled_SCL_Pin D4

extern Adafruit_SSD1306 display;

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire, OLED_RESET);

void init_OLED(){

  Wire.begin(oled_SDA_Pin,oled_SCL_Pin);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("OLED init failed"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}
#endif
