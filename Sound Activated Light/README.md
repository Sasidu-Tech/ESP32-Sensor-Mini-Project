# 🔊 ESP32 Sound Activated Light with LCD

A simple ESP32-based sound-controlled lighting system.

The system detects a sound or clap using a sound sensor and toggles an LED every time a new sound is detected.

### 🔊 First Sound → 💡 Light ON
### 🔊 Second Sound → 💡 Light OFF
### 🔊 Third Sound → 💡 Light ON
### 🔊 Fourth Sound → 💡 Light OFF

The current light status is also displayed on a 16x2 I2C LCD.

---

## 🚀 Features

- 🔊 Sound / clap detection
- 💡 LED ON/OFF control
- 🔄 Toggle light on every new sound
- 📟 16x2 I2C LCD status display
- ⚡ ESP32 based system
- 🧰 Simple and beginner-friendly circuit
- ⏱️ Debouncing / cooldown to prevent repeated triggering

---

## 🧩 Components Required

| Component | Quantity |
|---|---:|
| ESP32 Development Board | 1 |
| Sound Sensor Module (KY-037 / KY-038) | 1 |
| 16x2 I2C LCD | 1 |
| LED | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |

---

## 🔌 Circuit Connections

### 🔊 Sound Sensor

| Sound Sensor | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| OUT | GPIO 27 |

### 📟 16x2 I2C LCD

| LCD | ESP32 |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### 💡 LED

| LED | ESP32 |
|---|---|
| Anode (+) | GPIO 26 through 220Ω |
| Cathode (-) | GND |

---

## 📌 Pin Configuration

```text
ESP32
│
├── GPIO 27 → Sound Sensor OUT
│
├── GPIO 26 → LED
│
├── GPIO 21 → LCD SDA
│
└── GPIO 22 → LCD SCL
