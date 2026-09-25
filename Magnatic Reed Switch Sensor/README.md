🧲 ESP32 Magnetic Reed Switch Sensor

![Magnatic Reed Switch Sensor](images/Magnatic%20Read%20Switch%20(5).jpeg)

A simple ESP32-based magnetic reed switch project that detects whether a magnetic object is near the sensor.

The project can be used for simple door, window, cabinet, and security monitoring applications.

## 🚀 Features

- 🧲 Magnetic object detection
- 🔌 ESP32 GPIO input
- 🚪 Door / window monitoring
- 📟 Simple sensor status monitoring
- ⚡ Low-cost and easy to build
- 🛠️ Beginner-friendly ESP32 project

## 🧰 Components Required

- ESP32 Development Board
- Magnetic Reed Switch Sensor Module
- Jumper Wires
- Breadboard
- USB Cable

## 🔌 Wiring

| Reed Switch Module | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DO / OUT | GPIO 27 |

> **Note:** GPIO 27 is used as the sensor signal pin in this project.

## ⚙️ How It Works

A magnetic reed switch is an electrically operated switch that responds to a magnetic field.

When a magnet is brought close to the sensor, the reed switch changes its state.

### 🧲 Magnet Detected

MAGNET DETECTED
❌ Magnet Not Detected
NO MAGNET
The ESP32 reads the digital output from the sensor and determines the current state.
💻 Basic Code
#define MAGNET_PIN 27

void setup() {
  Serial.begin(115200);

  pinMode(MAGNET_PIN, INPUT);
}

void loop() {

  int sensorState = digitalRead(MAGNET_PIN);

  if (sensorState == LOW) {
    Serial.println("MAGNET DETECTED");
  } else {
    Serial.println("NO MAGNET");
  }

  delay(500);
}
If your particular sensor module gives the opposite output, simply change LOW and HIGH in the code.
🏠 Applications
🚪 Door open/close detection
🪟 Window security monitoring
🗄️ Cabinet monitoring
🔐 Simple security systems
🏠 Smart home projects
🤖 Robotics projects
🌐 IoT monitoring systems
📊 Working Principle
        🧲 Magnet
           ↓
    ┌───────────────┐
    │ Reed Switch   │
    │    Sensor     │
    └───────┬───────┘
            │
            ↓
         ESP32
            │
            ↓
    Detection Status
📸 Project
ESP32 + Magnetic Reed Switch Sensor
A simple mini project for learning digital sensors and ESP32 GPIO control.

👨‍💻 Author
Sasidu-Tech
GitHub: https://github.com/Sasidu-Tech⁠

📜 License
This project is licensed under the MIT License.
