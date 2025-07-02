#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H
extern Adafruit_SSD1306 display;
extern const char* ssid;
extern const char* password;

void connect_to_WiFi()
{
  WiFi.begin(ssid,password);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("WiFi connecting...");
  display.display();

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("IP:");
  Serial.println(WiFi.localIP());

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("WiFi connected!!");
  display.println(WiFi.localIP());
  display.display();
  delay(2000);
}
#endif