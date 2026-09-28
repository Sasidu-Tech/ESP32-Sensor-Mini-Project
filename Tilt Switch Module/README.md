🔄 Tilt Switch Module with ESP32 and 16x2 I2C LCD

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/jE4rYiFMvIc?si=taw08MVuS8qn2jaE)

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Tilt%20Switch%20Module/images/Tilt%20module%20(2).jpeg" alt="ESP32 Wi-Fi Scanner" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/Tilt%20Switch%20Module/images/Tilt%20module%20(1).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>



A simple Tilt Switch Detection System using an ESP32, Tilt Switch Module, LED indicator, and 16×2 I2C LCD.

The system detects a change in orientation or tilt using the sensor signal on GPIO 15. When the programmed tilt condition is detected, an LED connected to GPIO 14 provides a visual indication, while the LCD displays the current status.

📌 Project Overview

The Tilt Switch Module contains a small mechanical element that changes its electrical state when the module is tilted or moved.

In this project:

- GPIO 15 reads the Tilt Switch signal.
- GPIO 14 controls the external LED indicator.
- GPIO 21 and GPIO 22 are used for I2C LCD communication.
- The LCD displays the tilt status.

🧰 Components Required

- ESP32 Dev Module
- Tilt Switch Module
- 16×2 I2C LCD
- LED
- 220Ω resistor
- Jumper wires
- Breadboard
- USB Cable

🔌 Wiring

Tilt Switch Module

Module Pin| ESP32
VCC / +| 3.3V
GND / -| GND
S / Signal| GPIO 15

LED Indicator

LED Pin| ESP32
Anode (+)| GPIO 14 through 220Ω resistor
Cathode (-)| GND

16×2 I2C LCD

LCD Pin| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

🔗 Connection Summary

Tilt Switch Module       ESP32
--------------------------------
VCC / +            ────  3.3V
GND / -            ────  GND
S / Signal         ────  GPIO 15


LED Indicator             ESP32
--------------------------------
Anode (+)           ────  GPIO 14
                       │
                     220Ω
                       │
Cathode (-)         ────  GND


I2C LCD                   ESP32
--------------------------------
VCC                 ────  5V
GND                 ────  GND
SDA                 ────  GPIO 21
SCL                 ────  GPIO 22

⚙️ How It Works

1. The Tilt Switch detects a change in orientation.
2. The sensor changes its digital signal on GPIO 15.
3. The ESP32 reads the sensor state.
4. When the programmed tilt condition is detected, GPIO 14 turns the LED ON.
5. The LCD displays the current tilt status.

Normal Position

Tilt: Normal
LED: OFF

Tilt Detected

Tilt: Detected
LED: ON

«Note: The actual HIGH/LOW state for the detected position depends on the specific module and its orientation. If the status is reversed, the condition in the Arduino code can be inverted.»

💻 Arduino Libraries

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Required libraries:

- "Wire"
- "LiquidCrystal_I2C"

🧪 Basic Arduino Code

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TILT_PIN 15
#define LED_PIN 14

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(TILT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Tilt Switch");
}

void loop() {

  int tiltState = digitalRead(TILT_PIN);

  lcd.setCursor(0, 1);

  if (tiltState == HIGH) {
    digitalWrite(LED_PIN, HIGH);

    lcd.print("Tilt: Detected ");
  } 
  else {
    digitalWrite(LED_PIN, LOW);

    lcd.print("Tilt: Normal   ");
  }

  delay(200);
}

«If your module works in the opposite logic, change "HIGH" to "LOW" in the detection condition.»

📟 LCD I2C Address

The commonly used I2C address is:

0x27

The project uses:

LiquidCrystal_I2C lcd(0x27, 16, 2);

If your LCD has a different I2C address, update the address in the code.

🚀 Applications

- Tilt detection
- Motion detection
- Anti-tamper systems
- Simple alarm systems
- Orientation monitoring
- Robotics projects
- IoT projects
- Embedded-system learning
- Safety monitoring systems

📁 Suggested Project Structure

Tilt-Switch-ESP32/
│
├── code/
│   └── tilt_switch.ino
│
├── images/
│   └── tilt-switch-wiring.png
│
├── demo/
│   └── demo.mp4
│
└── README.md

⚠️ Important Notes

- Power the Tilt Switch Module according to the voltage requirements of your specific module.
- A 220Ω resistor should be used with the external LED.
- Make sure all components share a common GND.
- The tilt detection logic may need to be inverted depending on sensor orientation.
- The LCD uses SDA = GPIO 21 and SCL = GPIO 22.

👨‍💻 Author

Sasidu-Tech

BICT Student – Rajarata University of Sri Lanka

📄 License

This project is licensed under the MIT License.

© 2026 Sasidu-Tech
