## 🔴 IR Sensor Module with ESP32 and 16x2 I2C LCD

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/7UzmOmfon9I?si=5JgQMI6IaP_Swl2G)

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/IR%20Sensor/images/IR%20Sensor%20(1).jpeg" alt="ESP32 Wi-Fi Scanner" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/IR%20Sensor/images/IR%20Sensor%20(2).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>



A simple IR Sensor / Obstacle Detection project using an ESP32, IR sensor module, and a 16×2 I2C LCD. The system detects nearby objects using infrared light and displays the detection status on the LCD.

📌 Project Overview

The IR sensor module contains an IR transmitter and receiver. The transmitter emits infrared light, and the receiver detects reflected infrared light from nearby objects.

In this project:

- The IR sensor detects an object.
- The sensor sends a digital signal through the OUT pin.
- ESP32 reads the signal using GPIO 15.
- The detection status is displayed on the 16×2 I2C LCD.

🧰 Components Required

- ESP32 Dev Module
- IR Sensor / Obstacle Detection Module
- 16×2 I2C LCD
- Jumper Wires
- Breadboard
- USB Cable

🔌 Wiring

IR Sensor Module

Sensor Pin| ESP32
VCC| 3.3V
GND| GND
OUT| GPIO 15
EN| Not Used

16×2 I2C LCD

LCD Pin| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

🔗 Connection Summary

IR Sensor          ESP32
-------------------------
VCC       ──────── 3.3V
GND       ──────── GND
OUT       ──────── GPIO 15
EN        ──────── Not Used


I2C LCD             ESP32
--------------------------
VCC       ──────── 5V
GND       ──────── GND
SDA       ──────── GPIO 21
SCL       ──────── GPIO 22

⚙️ How It Works

1. The IR transmitter sends infrared light.
2. When an object is close to the sensor, some IR light is reflected back.
3. The IR receiver detects the reflected signal.
4. The sensor module changes its digital OUT signal.
5. ESP32 reads the signal through GPIO 15.
6. The LCD displays whether an object is detected.

Example — No Object

IR Sensor:
Status: Clear

Example — Object Detected

IR Sensor:
Status: Detected

«Note: Some IR sensor modules output LOW when an object is detected, while others may behave differently. Check your module and adjust the "HIGH/LOW" condition in the code if necessary.»

💻 Arduino Libraries

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Required libraries:

- "Wire"
- "LiquidCrystal_I2C"

🧪 Basic Arduino Code

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define IR_PIN 15

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(IR_PIN, INPUT);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("IR Sensor");
}

void loop() {

  int sensorState = digitalRead(IR_PIN);

  lcd.setCursor(0, 1);

  if (sensorState == LOW) {
    lcd.print("Object Detected ");
  } else {
    lcd.print("Status: Clear   ");
  }

  delay(200);
}

🎛️ Sensitivity Adjustment

Most IR obstacle sensor modules have a small potentiometer.

You can rotate the potentiometer to adjust the distance/sensitivity at which an object is detected.

📟 LCD I2C Address

The common LCD address is:

0x27

If your LCD uses another address, change:

LiquidCrystal_I2C lcd(0x27, 16, 2);

For example:

LiquidCrystal_I2C lcd(0x3F, 16, 2);

🚀 Applications

- Obstacle detection
- Robot cars
- Line-following robots
- Object counting
- Automatic doors
- Parking systems
- Smart automation
- Security systems
- IoT sensor projects

📁 Suggested Project Structure

IR-Sensor-ESP32/
│
├── code/
│   └── ir_sensor.ino
│
├── images/
│   └── ir-sensor-wiring.png
│
└── README.md

⚠️ Important Notes

- Check the pin labels on your specific IR sensor module before connecting it.
- Use 3.3V when the module is compatible with 3.3V logic.
- Keep ESP32 and sensor GND connected.
- The detection logic can be inverted depending on the module.
- Adjust the onboard potentiometer for suitable detection sensitivity.

👨‍💻 Author

Sasidu-Tech

BICT Student – Rajarata University of Sri Lanka

📄 License

This project is licensed under the MIT License.

© 2026 Sasidu-Tech
