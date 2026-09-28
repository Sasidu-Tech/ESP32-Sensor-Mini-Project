⚪ Ball Switch Sensor with ESP32 and 16x2 I2C LCD

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/t0vUzV7fVeo?si=j58MJKom9sZrc-AR)
<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Ball%20Switch%20Module/images/Ball%20Switch%20Module%20(1).jpeg" alt="ESP32 Wi-Fi Scanner" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Ball%20Switch%20Module/images/Ball%20Switch%20Module%20(2).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>

A simple Ball Switch Sensor project using an ESP32 and a 16×2 I2C LCD. The sensor detects movement or changes in orientation and displays the current status on the LCD.

📌 Project Overview

The Ball Switch Sensor contains a small conductive ball that moves when the module is tilted or moved. This changes the sensor's electrical state, allowing the ESP32 to detect movement.

The detected status is displayed on a 16×2 I2C LCD.

🧰 Components Required

- ESP32 Dev Module
- Ball Switch Sensor Module
- 16×2 I2C LCD
- Jumper Wires
- Breadboard
- USB Cable

🔌 Wiring

Ball Switch Sensor

Sensor Pin| ESP32
VCC| 3.3V
GND| GND
S / DO| GPIO 15

16×2 I2C LCD

LCD Pin| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

🔗 Connection Summary

Ball Switch        ESP32
-------------------------
VCC       ──────── 3.3V
GND       ──────── GND
S/DO      ──────── GPIO 15


I2C LCD            ESP32
-------------------------
VCC       ──────── 5V
GND       ──────── GND
SDA       ──────── GPIO 21
SCL       ──────── GPIO 22

⚙️ How It Works

1. The ball inside the sensor moves when the sensor is tilted or shaken.
2. The sensor changes its digital output state.
3. GPIO 15 reads the sensor signal.
4. The ESP32 determines whether movement/tilt is detected.
5. The result is displayed on the LCD.

Normal

Ball Switch
No Motion

LCD:
Motion: Normal
Status: OFF

Movement Detected

Ball Switch
Motion Detected

LCD:
Motion: Detected
Status: ON

«Note: The actual HIGH/LOW state can depend on the specific ball-switch module and its orientation. If the status is reversed, simply invert the condition in the Arduino code.»

💻 Arduino Libraries

This project uses:

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Install the LiquidCrystal_I2C library if it is not already installed.

📟 LCD I2C Address

The common LCD address is:

0x27

If your LCD does not display anything, scan the I2C address and change it if necessary.

Example:

LiquidCrystal_I2C lcd(0x27, 16, 2);

🚀 Applications

- Motion detection
- Tilt detection
- Simple alarm systems
- Orientation monitoring
- Anti-tamper systems
- Basic IoT sensor projects
- Arduino/ESP32 learning projects

📁 Suggested Project Structure

Ball-Switch-ESP32/
│
├── code/
│   └── ball_switch.ino
│
├── images/
│   └── ball-switch-wiring.png
│
├── demo/
│   └── demo.mp4
│
└── README.md

👨‍💻 Author

Sasidu-Tech

BICT Student – Rajarata University of Sri Lanka

📄 License

This project is licensed under the MIT License.

© 2026 Sasidu-Tech
