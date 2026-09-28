## 💡 Light Cup Sensor Module with ESP32 and 16x2 I2C LCD

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/vdhhJOVTlAk?si=JsoADxkph9eT-HMM)

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Light%20CUP%20module/images/light%20Cup%20Module%20(10).jpeg" alt="ESP32 Wi-Fi Scanner" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Light%20CUP%20module/images/light%20Cup%20Module%20(1).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>


A simple Light Cup Sensor project using an ESP32 and a 16×2 I2C LCD to measure and display the light level detected by the sensor module.

📌 Project Overview

The Light Cup module detects changes in surrounding light and provides an analog output that can be read by the ESP32 ADC.

In this project:

- The Light Cup sensor measures the surrounding light level.
- The analog output (AO) is connected to GPIO 34.
- ESP32 reads the analog sensor value.
- The value is displayed on a 16×2 I2C LCD.

ESP32's "analogRead()" can read an ADC value, with the standard ESP32 Arduino ADC resolution being 12-bit (0–4095).

🧰 Components Required

- ESP32 Dev Module
- Light Cup / Light Sensor Module
- 16×2 I2C LCD
- Jumper Wires
- Breadboard
- USB Cable

🔌 Wiring

Light Cup Module

Module Pin| ESP32
VCC| 3.3V
GND| GND
AO| GPIO 34
DO| Not Used

16×2 I2C LCD

LCD Pin| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

🔗 Connection Summary

Light Cup Module       ESP32
-----------------------------
VCC              ──── 3.3V
GND              ──── GND
AO               ──── GPIO 34
DO               ──── Not Used


I2C LCD                 ESP32
-----------------------------
VCC              ──── 5V
GND              ──── GND
SDA              ──── GPIO 21
SCL              ──── GPIO 22

GPIO 34 is an input-only GPIO on the classic ESP32, which makes it suitable for reading an analog sensor signal.

⚙️ How It Works

1. The Light Cup sensor detects the surrounding light.
2. The sensor generates an analog output.
3. GPIO 34 reads this analog signal.
4. ESP32 converts the signal into a digital ADC value.
5. The LCD displays the measured value.
6. The displayed value changes as the lighting conditions change.

Example LCD

Light Sensor
Value: 1850

Under different lighting conditions, the ADC value can change.

«Note: The exact value and whether a higher value represents more or less light depends on the specific Light Cup module and its circuit. Use the Serial Monitor to observe your module's readings and determine the direction of change.»

💻 Arduino Libraries

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Required libraries:

- "Wire"
- "LiquidCrystal_I2C"

🧪 Basic Arduino Code

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LIGHT_PIN 34

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Light Sensor");
}

void loop() {

  int lightValue = analogRead(LIGHT_PIN);

  Serial.print("Light Value: ");
  Serial.println(lightValue);

  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(lightValue);
  lcd.print("    ");

  delay(500);
}

📟 LCD I2C Address

The commonly used I2C LCD address is:

0x27

The code uses:

LiquidCrystal_I2C lcd(0x27, 16, 2);

If your LCD uses another I2C address, change the address accordingly.

🎛️ AO and DO

The Light Cup module may provide two outputs:

AO — Analog Output

Used in this project.

AO → GPIO 34

It provides a varying analog signal that can be read using "analogRead()".

DO — Digital Output

Not used in this project.

The onboard potentiometer can generally be used to adjust the digital detection threshold when using DO.

🚀 Applications

- Light intensity monitoring
- Smart lighting systems
- Automatic night-light projects
- Environmental monitoring
- IoT sensor projects
- ESP32 sensor experiments
- Robotics projects
- Beginner embedded-system projects

📁 Suggested Project Structure

Light-Cup-ESP32/
│
├── code/
│   └── light_cup.ino
│
├── images/
│   └── light-cup-wiring.png
│
├── demo/
│   └── demo.mp4
│
└── README.md

⚠️ Important Notes

- GPIO 34 is used only as an input on the classic ESP32, so it is suitable for this sensor's analog output.
- Check the exact voltage requirements of your Light Cup module before powering it.
- Do not exceed the ESP32 ADC input voltage limits.
- Connect the sensor and ESP32 grounds together.
- The LCD uses GPIO 21 (SDA) and GPIO 22 (SCL) in this project. These are the standard ESP32 Arduino SDA/SCL definitions.
- Sensor readings can vary depending on ambient light and the particular module.

👨‍💻 Author

Sasidu-Tech

BICT Student – Rajarata University of Sri Lanka

📄 License

This project is licensed under the MIT License.

© 2026 Sasidu-Tech
