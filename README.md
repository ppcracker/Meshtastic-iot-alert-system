# Meshtastic-iot-alert system project

Description: An off-grid, decentralized environmental monitoring system using ESP32, LoRa, and Meshtastic. Ideal for rural or remote deployment without internet or cellular access.


/sensor-node/

main.ino – Sensor node code

wiring-diagram.png – Wiring diagram for sensor node

/receiver-node/

receiver.ino – Receiver node code

wiring-diagram.png – Wiring diagram for receiver node

README.md – Project overview and setup instructions


# 🌐 Meshtastic IoT Alert System

An off-grid, decentralized environmental monitoring system using ESP32, LoRa, and Meshtastic. Designed to work in remote or disaster-prone areas without internet or cellular coverage. This project integrates IoT sensors with a LoRa-based mesh network for real-time environmental data and alert transmission.

---

## 🚀 Features

- 🌡️ Monitors Temperature, Humidity (DHT22)
- 🌫️ Detects Air Quality (MQ135)
- 📢 Triggers alerts via buzzer on sensor threshold breach
- 📡 Transmits data through LoRa using Meshtastic mesh network
- 📱 Receives and displays alerts on OLED/phone app/other nodes
- 🛠️ Easily extendable for additional sensors or internet connectivity

---

## 🔧 Hardware Used

| Component       | Quantity |
|----------------|----------|
| TTGO T-Beam (ESP32 + LoRa) | 2        |
| DHT22 Sensor    | 1        |
| MQ135 Gas Sensor| 1        |
| Passive Buzzer  | 1        |
| OLED Display (128x64) | 1 (optional) |

---

## 🧰 Setup Instructions

1. **Install Arduino IDE & ESP32 Board Manager**
2. **Wire the hardware** as per the schematic provided.
3. **Flash one node** with the `sensor-node/main.ino` code.
4. **Flash second node** with the `receiver-node/receiver.ino` code.
5. **Install Meshtastic app** on your phone or use Meshtastic Python CLI.
6. **Test the mesh network**: Send sensor data and receive alerts.

---

## 🖼️ Wiring Diagram

See `wiring-diagram.png` for complete wiring instructions.


---

## 📚 Learning Outcomes

- Understanding of LoRa mesh networks using Meshtastic
- Interfacing environmental sensors with microcontrollers
- Real-time alert systems for telecom or disaster management
- Modular IoT system design and off-grid communication

---

## 📄 License

This project is licensed under the MIT License – see [LICENSE](LICENSE) for details.

---

MIT License

Copyright (c) 2025 [Deepika Yadav]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
