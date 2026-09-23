📏 ESP32 Ultrasonic Distance Monitor

![Distance Measurement](images/Ultrasonic%20Sensor%20(1).jpeg)

A simple Ultrasonic Distance Measurement System built using an ESP32, HC-SR04 Ultrasonic Sensor, and 16×2 I2C LCD.

The system measures the distance between the ultrasonic sensor and an object and displays the measured distance on the LCD. The distance is also printed to the Serial Monitor.

---

🚀 Features

- 📡 Real-time distance measurement
- 📏 HC-SR04 ultrasonic sensor
- 🖥️ 16×2 I2C LCD display
- 📊 Serial Monitor output
- ⚡ ESP32-based system
- 🔧 Simple and beginner-friendly design
- 📦 Uses the NewPing library

---

🧰 Components Required

Component| Quantity
ESP32 Dev Module| 1
HC-SR04 Ultrasonic Sensor| 1
16×2 I2C LCD| 1
Jumper Wires| As required
Breadboard| 1
Resistors for ECHO voltage divider| 2

---

🔌 Circuit Connections

HC-SR04 → ESP32

HC-SR04| ESP32
VCC| 5V
GND| GND
TRIG| GPIO 5
ECHO| GPIO 18*

I2C LCD → ESP32

LCD| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

«⚠️ Important: The HC-SR04 ECHO signal can be 5V, while ESP32 GPIO pins are designed for 3.3V logic. Use a suitable voltage divider/level shifter between ECHO and GPIO 18.»

---

📚 Required Libraries

Install the following libraries through the Arduino IDE Library Manager:

NewPing
LiquidCrystal_I2C
Wire

"Wire" is normally included with the Arduino/ESP32 environment.

---

💻 Arduino Code

#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIGGER_PIN 5
#define ECHO_PIN 18
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("HC-SR04");

  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  delay(1500);

  lcd.clear();
}

void loop() {

  unsigned int distance = sonar.ping_cm();

  lcd.setCursor(0, 0);

  if (distance == 0) {
    lcd.print("Out of range   ");
  }
  else {
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" CM   ");
  }

  Serial.print("Distance: ");

  if (distance == 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}

---

🖥️ LCD Display

When an object is detected:

Distance: 25 CM

When the object is outside the configured range:

Out of range

---

🖥️ Serial Monitor

Set the Serial Monitor baud rate to:

115200

Example:

Distance: 25 cm
Distance: 24 cm
Distance: 25 cm
Distance: 26 cm

---

⚙️ How It Works

1. The ESP32 sends a trigger pulse to the HC-SR04.
2. The ultrasonic sensor sends an ultrasonic wave.
3. The wave reflects from an object.
4. The ECHO signal returns to the ESP32.
5. The "NewPing" library calculates the distance.
6. The measured distance is displayed on the LCD.
7. The same value is printed to the Serial Monitor.

Distance Formula

The basic distance calculation is based on the travel time of the ultrasonic wave:

Distance = Time × Speed of Sound ÷ 2

The division by 2 is required because the ultrasonic wave travels to the object and back.

---

📁 Project Structure

ESP32-Ultrasonic-Distance-Monitor/
│
├── ESP32_Ultrasonic_Distance_Monitor.ino
├── README.md
├── circuit/
│   └── circuit-diagram.png
│
└── demo/
    └── ultrasonic-demo.mp4

---

🔮 Future Improvements

This project can be extended with:

- 🚨 Buzzer distance alarm
- 🔴🟡🟢 Distance indication using LEDs
- 📱 Mobile monitoring
- 🌐 ESP32 Web Dashboard
- 📊 Distance monitoring graph
- 🚗 Smart parking system
- 🚪 Automatic door system
- 🤖 Robot obstacle detection

---

🎯 Learning Outcomes

Through this project, I practiced:

- ESP32 GPIO control
- Ultrasonic distance measurement
- I2C communication
- LCD interfacing
- Arduino libraries
- Sensor data processing
- Serial Monitor debugging

---

👨‍💻 Author

Sasidu Wishshanka

GitHub: Sasidu-Tech

---

📄 License

This project is licensed under the MIT License.

---

⭐ If you found this project useful, consider giving the repository a star!
