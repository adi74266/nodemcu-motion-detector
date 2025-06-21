#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- Wi‑Fi Credentials ---
const char* ssid     = "Yes";
const char* password = "111223344";

// --- Web server on port 80 ---
ESP8266WebServer server(80);

// --- OLED Setup ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- Pin Definitions ---
const int pirPin       = D5;   // PIR sensor OUT → GPIO14
const int ldrPin       = A0;   // LDR voltage divider → analog A0
const int LedPin  = D0;
const int oledSdaPin   = D3;   // OLED SDA → GPIO0
const int oledSclPin   = D4;   // OLED SCL → GPIO2

// --- Logic Flags ---
bool browserControl = true;   // true = enabled, false = disabled

// --- Light threshold ---
const int lightThreshold = 250;

void setup() {
  Serial.begin(115200);

  // Configure pins
  pinMode(pirPin, INPUT);
  pinMode(LedPin, OUTPUT);

  // Initializing I2C and OLED
  Wire.begin(oledSdaPin, oledSclPin);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED init failed"));
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Connecting to Wi‑Fi
  WiFi.begin(ssid, password);
  display.setCursor(0, 0);
  display.println("Wi-Fi connecting...");
  display.display();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.println();
  Serial.print("IP: "); Serial.println(WiFi.localIP());

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Wi-Fi connected!");
  display.println(WiFi.localIP());
  display.display();
  delay(2000);

  // Defining web routes
  server.on("/", []() {
    String html = "<!DOCTYPE html><html><style>";
    
      html +=" .btn {width: 120px;height: 45px;background-color:#28a745;color: white;border: none;border-radius: 6px;margin: 10px;font-size: 16px;cursor: pointer;transition: background-color 0.3s ease;}";
      html +=" strong{color:green;} .btn:hover {";
      html +=   "background-color: #1e7e34; /* Darker green on hover */";
       html +="}";

       html +=".btn-disable {";
        html += "background-color: #dc3545; /* Red */}";
      html += ".btn-disable:hover {";
       html += " background-color: #a71d2a; /* Darker red on hover */}";
       html += "</style><head><meta charset='utf-8'>";
      html +=             "<title>Motion System</title></head><body>";
    html += "<center><h2>Motion System Control</h2>";
    html += "System: <strong>" + String(browserControl ? "ON" : "OFF") + "</strong><br><br>";
        html += "<a href=\"/on\"><button class='btn'>Enable</button></a> ";
    html += "<a href=\"/off\"><button class='btn btn-disable' '>Disable</button></a>";
    html += "</center></body></html>";
    server.send(200, "text/html", html);
  });
  server.on("/on", []() {
    browserControl = true;
    server.sendHeader("Location", "/");
    server.send(303);
  });
  server.on("/off", []() {
    browserControl = false;
    server.sendHeader("Location", "/");
    server.send(303);
  });
  server.begin();
}

void loop() {
  server.handleClient();

  int ldrVal   = analogRead(ldrPin);
  bool motion  = digitalRead(pirPin);
  bool enabled = browserControl;

   
  // OLED display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("System: ");
  display.println(enabled ? "ON" : "OFF");
  display.print("Light State: ");
  display.println(ldrVal);
  display.print("Mode: ");
  display.println((ldrVal < lightThreshold) ? "Night" : "Day");
 // Status LEDs
 
  if (enabled && ldrVal < lightThreshold) {
    if (motion) {
      display.setCursor(0, 40);
      display.println("Motion Detected!");
      digitalWrite(LedPin,HIGH);
  }
     else {
      display.setCursor(0, 40);
      display.println("No Motion Detected");
       digitalWrite(LedPin,LOW);
    }
  }
  else {
    display.setCursor(0, 40);
    display.println("Idle");
     digitalWrite(LedPin,LOW);
  }

  display.display();
  delay(200);
}
