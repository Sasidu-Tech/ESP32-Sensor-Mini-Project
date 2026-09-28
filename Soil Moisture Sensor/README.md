## 🌱 ESP32 Soil Moisture Sensor

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/41GUkl4Rrqk?si=St8DD7vQ28JuJamx)

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Soil%20Moisture%20Sensor/images/Soil%20Moisture%20Sensor%20(4).jpeg" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Soil%20Moisture%20Sensor/images/Soil%20Moisture%20Sensor%20(6).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>


A simple **Soil Moisture Monitoring System** built using an **ESP32**, Soil Moisture Sensor, and a 16x2 I2C LCD.

The system reads the moisture level of the soil through the sensor connected to **GPIO 34** and displays the moisture status on the LCD.

---

## 📌 Project Overview

This project demonstrates how an ESP32 can be used to monitor soil moisture in real time.

The Soil Moisture Sensor provides an analog value to the ESP32. The ESP32 reads this value and determines the soil moisture condition, which is then displayed on the LCD.

This project can be used as a basic building block for **Smart Agriculture, Smart Gardening, and Plant Monitoring Systems**.

---

## 🔧 Components Required

* ESP32 Development Board
* Soil Moisture Sensor
* 16x2 I2C LCD
* Breadboard
* Jumper Wires
* USB Cable

---

## 🔌 Circuit Connections

### 🌱 Soil Moisture Sensor

| Sensor Pin  | ESP32   |
| ----------- | ------- |
| VCC         | 3.3V    |
| GND         | GND     |
| AO / Signal | GPIO 34 |

### 📟 16x2 I2C LCD

| LCD Pin | ESP32    |
| ------- | -------- |
| VCC     | VIN / 5V |
| GND     | GND      |
| SDA     | GPIO 21  |
| SCL     | GPIO 22  |

> **Note:** GPIO 34 is an input-only ADC pin on the ESP32, which makes it suitable for reading the analog sensor signal.

---

## ⚙️ How It Works

1. The Soil Moisture Sensor detects the moisture level in the soil.
2. The sensor generates an analog output.
3. The ESP32 reads this analog signal through **GPIO 34**.
4. The sensor value is processed by the ESP32.
5. The soil moisture condition is displayed on the **16x2 I2C LCD**.

---

## 📊 Example Output

```text
Soil Moisture
Moist: 65%
```

or

```text
Soil Moisture
Dry: 25%
```

The exact sensor values can vary depending on the sensor type, soil condition, and calibration.

---

## 💻 Arduino Code

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SOIL_PIN 34

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  delay(2000);
  lcd.clear();
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil Sensor: ");
  Serial.println(soilValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Value:");
  lcd.setCursor(0, 1);
  lcd.print(soilValue);

  delay(1000);
}
```

---

## 🚀 Applications

* 🌱 Smart Agriculture
* 🪴 Smart Plant Monitoring
* 💧 Automatic Irrigation Systems
* 🌿 Smart Gardening
* 🏡 Home Plant Monitoring
* 🤖 IoT Agriculture Projects

---

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](YOUR_YOUTUBE_VIDEO_LINK)

---

## 🔗 Connect With Me

**GitHub:**
https://github.com/Sasidu-Tech

**LinkedIn:**
https://www.linkedin.com/in/sasidu-wishshanka-434938428

---

## 👨‍💻 Author

**Sasidu-Tech**

BICT Student | Embedded Systems | IoT | Robotics | Networking | Cyber Security

---

## 📄 License

This project is licensed under the **MIT License**.

© 2026 Sasidu-Tech
