# 🔐 RFID RC522 + ESP32 + 16×2 I2C LCD


![ESP32 Wi-Fi Scanner](https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/RFID-RC522/images/RFID-RC522%20(1).jpeg)

A simple RFID-based identification system built using an **ESP32**, **RC522 RFID module**, and **16×2 I2C LCD**.

When an RFID card or tag is scanned, the system detects the card and displays its **UID** on the LCD and Serial Monitor.

---

## 📌 Project Overview

This project demonstrates how to interface an **RC522 RFID reader** with an **ESP32** using SPI communication and display the scanned RFID card UID on a 16×2 I2C LCD.

### ✨ Features

* 📡 RFID card/tag detection
* 🔐 RC522 RFID reader
* 🖥️ 16×2 I2C LCD display
* 🆔 RFID UID display
* 📟 Serial Monitor output
* ⚡ ESP32-based system
* 🔌 Simple SPI + I2C communication

---

## 🛠️ Components Required

| Component         |    Quantity |
| ----------------- | ----------: |
| ESP32 Dev Module  |           1 |
| RC522 RFID Module |           1 |
| 16×2 I2C LCD      |           1 |
| RFID Card/Tag     |          1+ |
| Jumper Wires      | As required |

---

## 🔌 Wiring Diagram

### RC522 → ESP32

| RC522 Pin | ESP32 Pin |
| --------- | --------- |
| 3.3V      | 3.3V      |
| GND       | GND       |
| SDA / SS  | GPIO 5    |
| SCK       | GPIO 18   |
| MOSI      | GPIO 23   |
| MISO      | GPIO 19   |
| RST       | GPIO 4    |

### 16×2 I2C LCD → ESP32

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO 21   |
| SCL     | GPIO 22   |

> ⚠️ **Important:** The RC522 operates at 3.3V. Do not connect 5V directly to the RC522.

---

## 📚 Required Arduino Libraries

Install these libraries from the Arduino IDE Library Manager:

* **MFRC522**
* **LiquidCrystal_I2C**

The following ESP32 libraries are also used:

* `SPI.h`
* `Wire.h`

---

## ⚙️ How It Works

```text
        RFID Card / Tag
               ↓
          RC522 Reader
               ↓
          ESP32 Controller
          ↙            ↘
     Serial Monitor    I2C LCD
          ↓              ↓
       RFID UID       UID Display
```

1. The ESP32 initializes the RC522 RFID reader.
2. The LCD displays `Scan Card...`.
3. An RFID card/tag is placed near the RC522.
4. The RC522 reads the card UID.
5. ESP32 processes the UID.
6. The UID is displayed on the LCD.
7. The UID is also printed in the Serial Monitor.
8. The system returns to the card scanning state.

---

## 🖥️ LCD Display

### Initial Screen

```text
RFID SYSTEM
Scan Card...
```

### After Scanning

```text
Card Detected
A3:4F:92:1C
```

The displayed UID will depend on the RFID card/tag being used.

---

## 💻 SPI & I2C Communication

### RC522 — SPI

```text
SCK  → GPIO 18
MISO → GPIO 19
MOSI → GPIO 23
SS   → GPIO 5
RST  → GPIO 4
```

### LCD — I2C

```text
SDA → GPIO 21
SCL → GPIO 22
```

This project is a good example of using **two communication protocols at the same time**:

* **SPI** → RFID RC522
* **I2C** → LCD

---

## 🚀 Future Improvements

This basic RFID project can be expanded into:

* 👤 RFID Attendance System
* 🔐 RFID Door Lock
* 🚪 RFID Access Control System
* 📝 Student Identification System
* ☁️ RFID + Firebase Attendance
* 🔔 RFID Access with Buzzer
* 🔴 Access Granted / Access Denied LEDs
* 🗄️ RFID UID Database

---

## 📸 Project Showcase

Add your project images here:

```text
📁 images/
├── wiring-diagram.png
├── project-photo.jpg
└── lcd-display.jpg
```


## 🎯 Learning Outcomes

Through this project, I learned:

* ESP32 GPIO configuration
* SPI communication
* I2C communication
* RFID card detection
* RFID UID reading
* LCD interfacing
* Arduino library integration
* Basic embedded-system development

---

## 👨‍💻 Author

**Sasidu Wishshanka**

BICT Student – Rajarata University of Sri Lanka

**Interests:**

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
