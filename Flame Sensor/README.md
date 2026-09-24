🔥 ESP32 Flame & Fire Detection System

![Flame Sensor](images/Flame%20Sensor%20(3).jpeg)

An ESP32-based flame detection system using a **Flame Sensor** and **16x2 I2C LCD Display**.

The system detects the presence of a flame and displays the current status on the LCD.

## 🚀 Features

- 🔥 Flame detection
- 📟 16x2 I2C LCD display
- 📊 Analog flame sensor reading
- 🔌 Digital flame detection output
- ⚡ ESP32-based system
- 💻 Simple and low-cost IoT project

## 🧰 Components Required

- ESP32 Development Board
- Flame Sensor Module
- 16x2 I2C LCD Display
- Breadboard
- Jumper Wires
- USB Cable

## 🔌 Wiring

### 🔥 Flame Sensor

| Flame Sensor | ESP32 |
|---|---|
| AO | GPIO 34 |
| DO | GPIO 15 |
| VCC | 3.3V |
| GND | GND |

### 📟 16x2 I2C LCD

| LCD | ESP32 |
|---|---|
| SDA | GPIO 22 |
| SCL | GPIO 21 |
| VCC | 5V / VIN |
| GND | GND |

> **Note:** The project uses custom I2C pins with SDA on GPIO 22 and SCL on GPIO 21.

## ⚙️ How It Works

The flame sensor detects infrared radiation produced by a flame.

The sensor provides two outputs:

- **AO (Analog Output)** → Connected to GPIO 34
- **DO (Digital Output)** → Connected to GPIO 15

The ESP32 reads the sensor and displays the detection status on the LCD.

### LCD Output

When a flame is detected:


FIRE DETECTED
FLAME / FIRE
When no flame is detected:
NO FIRE
NORMA

💻 I2C Configuration
Wire.begin(22, 21);
SDA → GPIO 22
SCL → GPIO 21
The LCD I2C address is commonly 0x27, but it can vary depending on the module.

📚 Required Libraries
Install the following library through Arduino IDE:
LiquidCrystal_I2C
Built-in:
#include <Wire.h>

🔥 Applications
Fire detection systems
Safety monitoring
IoT security projects
Smart home systems
Laboratory fire monitoring
Embedded systems projects

📸 Project
ESP32 + Flame Sensor + 16x2 I2C LCD

👨‍💻 Author
Sasidu-Tech
GitHub: https://github.com/Sasidu-Tech⁠

📜 License
This project is licensed under the MIT License.
