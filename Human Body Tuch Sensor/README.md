# 👆 ESP32 Human Body Touch Sensor

![ESP32 Human Body Touch Sensor](images/esp32-wifi-scanner.png)

A simple touch detection project using an **ESP32** and **TTP223 Capacitive Touch Sensor**.

The TTP223 sensor detects human touch by sensing changes in capacitance. When a finger touches the sensing area, the sensor output becomes HIGH. 1

---

## 📌 Project Overview

This project demonstrates how to interface a **TTP223 Capacitive Touch Sensor** with an ESP32.

Instead of using a traditional push button, the TTP223 allows the user to control the ESP32 simply by touching the sensor surface.

### Working Logic


Touch Detected     → HIGH
No Touch           → LOW
🎯 Features
👆 Human touch detection
⚡ Capacitive touch sensing
🔌 ESP32 GPIO input
💡 LED touch indication
🖥️ Serial Monitor output
🔧 Simple beginner-friendly project
🔘 Push-button replacement
🛠️ Components Required

Component
Quantity
ESP32 Development Board
1
TTP223 Touch Sensor
1
LED
1
220Ω Resistor
1
Breadboard
1
Jumper Wires
As required

🔌 Circuit Connections
TTP223 → ESP32
TTP223 Pin
ESP32
VCC
3.3V
GND
GND
OUT
GPIO 27
The TTP223 module supports approximately 2.0V–5.5V, so powering the module from the ESP32's 3.3V supply is suitable. �
Alphatronic +1
LED → ESP32
LED
ESP32
Anode (+)
GPIO 26
Cathode (-)
GND
Use a 220Ω resistor in series with the LED.

🔄 How It Works
       👆 Human Finger
             │
             ▼
     ┌────────────────┐
     │  TTP223 Touch  │
     │     Sensor     │
     └───────┬────────┘
             │
            OUT
             │
             ▼
     ┌────────────────┐
     │      ESP32     │
     │    GPIO 27     │
     └───────┬────────┘
             │
             ▼
        ┌─────────┐
        │   LED   │
        └─────────┘
The TTP223 uses capacitive sensing. When a human finger touches the sensing pad, the body's capacitance changes the sensor's electrical characteristics, causing the digital output to change state. �
Wasil Zafar

🖥️ Serial Monitor Output
Set the Serial Monitor to:
115200 baud
Without touching
No Touch
No Touch
No Touch
When touching the sensor
Touch Detected!
Touch Detected!
Touch Detected!
The onboard LED of many TTP223 modules also provides a visual indication when the sensor is triggered. �
Alphatronic

⚙️ Sensor Pins
The basic TTP223 module has three main connections:
VCC  → Power
GND  → Ground
OUT  → Digital Output
The default operation of common modules is active HIGH: touching the pad makes the output HIGH. �
SunFounder Documentation +1

🧪 Testing Procedure
Connect the TTP223 to the ESP32.
Connect the LED to GPIO 26.
Upload the Arduino code.
Open Serial Monitor.
Set baud rate to 115200.
Touch the TTP223 sensor.
Check the Serial Monitor.
The LED should turn ON while touch is detected.

⚠️ Troubleshooting
Touch is not detected

Check:
VCC  → 3.3V
GND  → GND
OUT  → GPIO 27
Also make sure you are touching the actual sensing pad.
LED is always ON
Check whether your particular TTP223 module is configured for active HIGH or active LOW. Some versions provide solder-jumper options for changing the output behavior. �
ComponentIndex
Sensor is too sensitive
TTP223 sensitivity depends on the sensing electrode and module configuration. Keep the sensor away from unnecessary conductive objects and electrical noise.

🚀 Future Improvements
This project can be upgraded into:
💡 Touch Controlled Light
🔔 Touch Alarm
🔐 Touch-Based Door Lock
🏠 Smart Home Touch Switch
🎵 Touch Music Controller
⚡ Touch ON/OFF System
📱 IoT Touch Control
🔢 Touch-Based Digital Counter

🧠 What I Learned
Through this project, I learned:
Capacitive touch sensing
Human body capacitance
ESP32 digital GPIO
digitalRead()
LED control
Sensor interfacing
Serial Monitor debugging
Replacing mechanical buttons with touch sensors

🔧 Technologies
ESP32
Arduino IDE
C/C++
TTP223 Capacitive Touch Sensor
Digital GPIO
LED

📂 Project Structure
ESP32-Human-Body-Touch-Sensor/
│
├── Code/
│   └── Touch_Sensor.ino
│
├── Circuit/
│   └── circuit-diagram.png
│
├── Images/
│   └── project-photo.jpg
│
├── Demo/
│   └── demo.mp4
│
└── README.md

👨‍💻 Author
Sasidu-Tech
BICT Student | Networking | Cyber Security | IoT Developer
GitHub:
https://github.com/Sasidu-Tech⁠

📜 License
This project is licensed under the MIT License.
⭐ If you found this project useful, consider giving the repository a star!
