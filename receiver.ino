
================== Receiver Node OLED Display Script ==================
// This code is for an ESP32 with OLED to display incoming Meshtastic messages
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Waiting for data...");
  display.display();
}

void loop() {
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Msg Received:");
    display.println(msg);
    display.display();
  }
}
=======================================================================
