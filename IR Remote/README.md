📡 IR Remote Receiver Module with ESP32 and 16x2 I2C LCD


## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/Q4VB2j5S4r4?si=umDgWxa10fF6UTV-)

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/IR%20Remote/images/Ir%20Remote%20Module%20(1).jpeg" alt="ESP32 Wi-Fi Scanner" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/IR%20Remote/images/Ir%20Remote%20Module%20(2).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>





A simple IR Remote Receiver project using an ESP32, IR receiver module, and a 16×2 I2C LCD. The system receives infrared signals from a remote control and allows the ESP32 to process the received commands.

📌 Project Overview

An IR receiver module detects infrared signals transmitted by an IR remote control.

In this project:

- The IR receiver receives the remote signal.
- ESP32 reads the signal through GPIO 15.
- The ESP32 decodes the received IR command.
- The 16×2 I2C LCD displays the system status or received command.

This is a useful beginner-level project for learning IR communication with ESP32.

🧰 Components Required

- ESP32 Dev Module
- IR Receiver Module (VS1838B or similar)
- IR Remote Control
- 16×2 I2C LCD
- Jumper Wires
- Breadboard
- USB Cable

🔌 Wiring

IR Receiver Module

IR Module Pin| ESP32
OUT / Signal| GPIO 15
VCC| 3.3V
GND| GND

16×2 I2C LCD

LCD Pin| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

🔗 Connection Summary

IR Receiver       ESP32
-------------------------
OUT       ─────── GPIO 15
VCC       ─────── 3.3V
GND       ─────── GND


I2C LCD           ESP32
-------------------------
VCC       ─────── 5V
GND       ─────── GND
SDA       ─────── GPIO 21
SCL       ─────── GPIO 22

⚙️ How It Works

1. Press a button on the IR remote.
2. The remote sends an infrared signal.
3. The IR receiver detects the signal.
4. GPIO 15 receives the signal from the receiver.
5. The ESP32 decodes the IR command.
6. The LCD can display the received command or system status.

Example LCD

IR Remote Ready
Press a Button...

After pressing a remote button:

Button Pressed
Command: 0x...

The exact decoded command depends on the remote control and its IR protocol.

💻 Required Arduino Libraries

For the IR receiver:

#include <IRremote.hpp>

For the LCD:

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Recommended libraries:

- IRremote
- LiquidCrystal_I2C

🧪 Basic IR Receiver Code

#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define IR_PIN 15

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  IrReceiver.begin(IR_PIN);

  lcd.setCursor(0, 0);
  lcd.print("IR Remote Ready");
  lcd.setCursor(0, 1);
  lcd.print("Press a Button");
}

void loop() {

  if (IrReceiver.decode()) {

    Serial.println("IR Signal Received");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Button Pressed");

    lcd.setCursor(0, 1);
    lcd.print("Signal Received");

    IrReceiver.resume();
  }
}

📟 LCD I2C Address

The commonly used I2C address is:

0x27

If your LCD uses another address, update:

LiquidCrystal_I2C lcd(0x27, 16, 2);

For example:

LiquidCrystal_I2C lcd(0x3F, 16, 2);

🚀 Applications

- IR remote controlled systems
- Home automation
- TV/AC remote experiments
- Robot control
- IoT control systems
- ESP32 learning projects
- Wireless command interfaces

📁 Suggested Project Structure

IR-Remote-ESP32/
│
├── code/
│   └── ir_remote.ino
│
├── images/
│   └── ir-remote-wiring.png
└── README.md

⚠️ Important Notes

- Check the pin labels on your specific IR receiver module before wiring.
- Use 3.3V for the IR receiver when using an ESP32 unless your specific module states otherwise.
- Make sure ESP32, IR receiver, and LCD share a common GND.
- The IR command values vary between different remote controls.
- Avoid exposing private device information such as Wi-Fi credentials or MAC addresses in public screenshots.

👨‍💻 Author

Sasidu-Tech

BICT Student – Rajarata University of Sri Lanka

📄 License

This project is licensed under the MIT License.

© 2026 Sasidu-Tech
