# 🌧️ Rain Drop Sensor + ESP32 + 16×2 I2C LCD

![ESP32 Wi-Fi Scanner](https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Raindrop%20Module/images/Raindrop%20module%20(10).jpeg)

A simple **Rain Detection System** built using an **ESP32**, **Rain Drop Sensor Module**, and **16×2 I2C LCD**.

The system detects rain using both the **Analog (AO)** and **Digital (DO)** outputs of the rain sensor and displays the rain status on the LCD.

---

## 📌 Project Overview

This project demonstrates how to interface a rain detection sensor with an ESP32 and display the detected rain status on an I2C LCD.

The rain sensor provides two types of outputs:

* **AO (Analog Output)** → Provides a variable sensor reading.
* **DO (Digital Output)** → Provides a simple rain/no-rain detection signal.

---

## ✨ Features

* 🌧️ Rain detection
* 📊 Analog rain sensor reading
* 🔘 Digital rain detection
* 📟 16×2 I2C LCD display
* ⚡ ESP32-based system
* 🔌 Simple sensor interfacing
* 📈 Real-time sensor monitoring

---

## 🛠️ Components Required

| Component               |    Quantity |
| ----------------------- | ----------: |
| ESP32 Dev Module        |           1 |
| Rain Drop Sensor Module |           1 |
| 16×2 I2C LCD            |           1 |
| Jumper Wires            | As required |
| USB Cable               |           1 |

---

## 🔌 Wiring

### 🌧️ Rain Sensor → ESP32

| Rain Sensor Pin | ESP32   |
| --------------- | ------- |
| VCC             | 3.3V    |
| GND             | GND     |
| AO              | GPIO 34 |
| DO              | GPIO 15 |

### 📟 16×2 I2C LCD → ESP32

| LCD Pin | ESP32   |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| SDA     | GPIO 21 |
| SCL     | GPIO 22 |

### 📌 Pin Configuration

```text
Rain Sensor AO → GPIO 34
Rain Sensor DO → GPIO 15

LCD SDA → GPIO 21
LCD SCL → GPIO 22
```

GPIO 34 is an input-only GPIO on the classic ESP32, making it suitable for reading the sensor's analog output.

---

## 🔧 How It Works

```text
       Rain Drops
           ↓
   ┌─────────────────┐
   │  Rain Sensor    │
   │                 │
   │ AO         DO   │
   └─┬──────────┬────┘
     │          │
     ↓          ↓
 GPIO 34     GPIO 15
     │          │
     └────┬─────┘
          ↓
       ESP32
          │
          ↓
     I2C LCD
     SDA → 21
     SCL → 22
          ↓
   Rain Status Display
```

---

## 📊 Sensor Outputs

### Analog Output — AO

The **AO pin** provides a variable analog value depending on the amount of water detected by the sensor surface.

```cpp
int rainValue = analogRead(34);
```

The exact value range and direction can vary depending on the particular sensor module and its adjustment/calibration.

### Digital Output — DO

The **DO pin** provides a digital signal based on the threshold set using the sensor module's potentiometer.

```cpp
int rainStatus = digitalRead(15);
```

You can adjust the potentiometer on the rain sensor module to change the digital detection threshold.

---

## 📟 LCD Display Example

### No Rain

```text
Rain: No Rain
Value: 3200
```

### Rain Detected

```text
Rain: Detected
Value: 850
```

> The actual analog values depend on the sensor, water level, surface condition, and potentiometer/module configuration.

---

## 📚 Required Libraries

For the LCD:

* `LiquidCrystal_I2C`
* `Wire`

The ESP32 Arduino core provides the GPIO functions used for reading digital and analog inputs.

---

## ⚙️ Communication

This project uses:

```text
Rain Sensor → Analog / Digital GPIO
LCD         → I2C
```

### I2C Pins

```text
SDA → GPIO 21
SCL → GPIO 22
```

### Sensor Pins

```text
AO → GPIO 34
DO → GPIO 15
```

---

## 🎯 Learning Outcomes

Through this project, I learned:

* ESP32 GPIO configuration
* Analog sensor reading
* Digital sensor reading
* I2C LCD interfacing
* Sensor threshold adjustment
* Real-time environmental monitoring
* Basic embedded-system development

---

## 🚀 Future Improvements

This project can be expanded into:

* ☔ Automatic rain alarm
* 🌱 Smart irrigation system
* 🪟 Automatic window closing system
* 📱 ESP32 Wi-Fi rain monitoring
* ☁️ IoT weather monitoring
* 📊 Web-based rain monitoring dashboard
* 🔔 Buzzer alert when rain is detected

---

## 📸 Project Showcase

Add your project images:

```text
📁 images/
├── wiring-diagram.png
├── project-photo.jpg
└── lcd-display.jpg
```

Example:

```markdown
![Rain Sensor Wiring Diagram](images/wiring-diagram.png)
```

---

## 🎥 Demo

Add your demonstration video here:

```text
Demo Video: YOUR_DEMO_LINK
```

---

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
