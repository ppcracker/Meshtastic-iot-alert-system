// Meshtastic Sensor Node: ESP32 + DHT22 + MQ135 + Buzzer
// Purpose: Monitor environment and send alerts via LoRa mesh

#include <DHT.h>
#define DHTPIN 14     // DHT sensor connected to GPIO14
#define DHTTYPE DHT22
#define MQ135PIN 34   // MQ135 connected to analog GPIO34
#define BUZZERPIN 12  // Buzzer connected to GPIO12

DHT dht(DHTPIN, DHTTYPE);

// Threshold values
#define TEMP_THRESHOLD 40.0
#define HUM_THRESHOLD 85.0
#define AQ_THRESHOLD 400

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(MQ135PIN, INPUT);
  pinMode(BUZZERPIN, OUTPUT);
  digitalWrite(BUZZERPIN, LOW);
  delay(3000); // Wait for sensor stabilization
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int air_quality = analogRead(MQ135PIN);

  // Format sensor data
  String data = "TEMP:" + String(temp) + "C, HUM:" + String(hum) + "%, AQ:" + String(air_quality);

  // Send data via Meshtastic (serial message)
  Serial.println(data);

  // Alert logic
  if (temp > TEMP_THRESHOLD || hum > HUM_THRESHOLD || air_quality > AQ_THRESHOLD) {
    digitalWrite(BUZZERPIN, HIGH);
    delay(1000);
    digitalWrite(BUZZERPIN, LOW);

    // Send critical alert
    Serial.println("ALERT: Sensor threshold exceeded!");
  }

  delay(10000); // Read every 10 seconds
}



/*
================== GitHub-Ready README Template ==================
# 🌐 Meshtastic IoT Alert System

An off-grid, decentralized environmental monitoring system using ESP32, LoRa, and Meshtastic. Ideal for rural or remote deployment without internet or cellular access.

## 🚀 Features
- Monitor temperature, humidity, and air quality
- Transmit alerts over a secure LoRa mesh network
- Use buzzer for local alerts
- Visualize messages via OLED or Meshtastic app

## 🔧 Hardware
- ESP32 + LoRa (e.g., TTGO T-Beam)
- DHT22, MQ135, buzzer, optional OLED

## 🧰 Setup
1. Flash [Meshtastic firmware](https://github.com/meshtastic/Meshtastic-device)
2. Connect sensors per wiring diagram
3. Upload the sensor code to the node
4. Use the receiver code to display messages

## 📸 Images
- Wiring Diagram (attached)
- Screenshots of OLED display & App

## 📚 Learning Outcomes
- LoRa mesh networking for telecom applications
- IoT data collection and alert systems
- Firmware development with ESP32
- Real-world deployment planning and calibration

## 📄 License
MIT License
==================================================================
*/
