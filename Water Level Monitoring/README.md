# 💧 Water Level Sensor + ESP32 + 16×2 I2C LCD

![ESP32 Wi-Fi Scanner](https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Water%20Level%20Monitoring/images/Rain%20Sensor%20module%20(10).jpeg)

A simple **Water Level Monitoring System** built using an **ESP32**, **Water Level Sensor**, and **16×2 I2C LCD**.

The system reads the water level using the sensor's analog output and displays the water level status on the LCD.

---

## 📌 Project Overview

This project demonstrates how to connect an analog water level sensor to an ESP32 and display the measured sensor value and water level status using an I2C LCD.

The sensor detects the amount of water touching its sensing surface and produces an analog output. The ESP32 reads this value through an analog input pin.

---

## ✨ Features

* 💧 Water level detection
* 📊 Analog sensor reading
* 📟 16×2 I2C LCD display
* ⚡ ESP32-based monitoring
* 🔄 Real-time water level monitoring
* 📈 Low / Normal / High level indication
* 🔌 Simple sensor interfacing

---

## 🛠️ Components Required

| Component                 |    Quantity |
| ------------------------- | ----------: |
| ESP32 Dev Module          |           1 |
| Water Level Sensor Module |           1 |
| 16×2 I2C LCD              |           1 |
| Jumper Wires              | As required |
| USB Cable                 |           1 |

---

## 🔌 Wiring Diagram

### 💧 Water Level Sensor → ESP32

| Sensor Pin | ESP32 Pin |
| ---------- | --------- |
| VCC        | 3.3V      |
| GND        | GND       |
| AO         | GPIO 34   |

### 📟 16×2 I2C LCD → ESP32

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO 21   |
| SCL     | GPIO 22   |

### 📌 Pin Configuration

```text
Water Sensor AO → GPIO 34

LCD SDA → GPIO 21
LCD SCL → GPIO 22
```

---

## ⚙️ How It Works

```text
       Water
         ↓
┌──────────────────┐
│ Water Level      │
│ Sensor           │
└────────┬─────────┘
         │
         │ Analog Signal
         ↓
     GPIO 34
         │
         ↓
       ESP32
         │
         │ I2C
         ↓
   ┌──────────────┐
   │ 16×2 I2C LCD │
   └──────────────┘
         ↓
   Water Level
    Display
```

### Working Process

1. The water level sensor is placed in the water container.
2. The sensor produces an analog signal according to the detected water level.
3. ESP32 reads the analog value through **GPIO 34**.
4. The program compares the value with predefined thresholds.
5. The LCD displays the current water level status.
6. The system continuously updates the reading.

---

## 📊 Example Water Level Status

### Low Level

```text
Water Level:
LOW
```

### Normal Level

```text
Water Level:
NORMAL
```

### High Level

```text
Water Level:
HIGH
```

> The actual analog values depend on the sensor type, water conductivity, sensor position, and calibration. Threshold values should therefore be adjusted during testing.

---

## 📟 LCD Interface

The LCD uses **I2C communication**.

```text
SDA → GPIO 21
SCL → GPIO 22
```

The common I2C LCD address is:

```text
0x27
```

If the LCD does not display anything, the I2C address may be different, such as `0x3F`.

---

## 💻 Example Code


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define WATER_SENSOR_PIN 34

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Water Level");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...");
  
  delay(2000);
  lcd.clear();
}

void loop() {

  int waterValue = analogRead(WATER_SENSOR_PIN);

  Serial.print("Water Level Value: ");
  Serial.println(waterValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water:");
  lcd.print(waterValue);

  lcd.setCursor(0, 1);

  if (waterValue < 1000) {
    lcd.print("LOW");
  }
  else if (waterValue < 2500) {
    lcd.print("NORMAL");
  }
  else {
    lcd.print("HIGH");
  }

  delay(1000);
}
```

---

## 📚 Required Library

Install:

```text
LiquidCrystal_I2C


The following libraries are included with the ESP32 Arduino environment:

```cpp
Wire.h
```

---

## 🔧 Calibration

The threshold values in the example are only starting values.

You can check the Serial Monitor:

```text
Water Level Value: 850
Water Level Value: 1450
Water Level Value: 2300
Water Level Value: 3100
```

Then test the sensor at different water levels and adjust:

```cpp
if (waterValue < 1000)
```

```cpp
else if (waterValue < 2500)
```

according to your sensor.

---

## 🎯 Learning Outcomes

Through this project, I learned:

* ESP32 analog input
* Water level sensing
* ADC sensor readings
* I2C LCD interfacing
* Sensor calibration
* Threshold-based monitoring
* Real-time embedded-system development

---

## 🚀 Future Improvements

This project can be upgraded with:

* 🚨 Buzzer alert for low water
* 💧 Automatic water pump control
* 📱 ESP32 Wi-Fi monitoring
* ☁️ IoT water level dashboard
* 📊 Web-based monitoring
* 🔔 Mobile notifications
* ⚙️ Automatic tank filling system

---

## 📸 Project Showcase

Recommended project structure:

```text
Water-Level-Sensor-ESP32/
│
├── code/
│   └── water_level_sensor.ino
│
├── images/
│   ├── wiring-diagram.png
│   └── project-photo.jpg
│
└── README.md
```

Add the wiring diagram:



## 👨‍💻 Author

**Sasidu Wishshanka**

BICT Student – Rajarata University of Sri Lanka

### Interests

* 🌐 Networking
* 🔐 Cyber Security
* 🤖 Robotics
* 📡 IoT
* 💻 Embedded Systems
* ⚙️ ESP32 & Arduino

---

## 📜 License

This project is licensed under the **MIT License**.

Copyright © 2026 **Sasidu-Tech**
