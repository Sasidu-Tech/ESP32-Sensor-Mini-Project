# ⏰ ESP32 DS3231 RTC Clock with LCD

![Real-Time-Clock(RTC)](images/esp32-wifi-scanner.png)

A simple Real-Time Clock (RTC) project using an **ESP32**, **DS3231 RTC Module**, and **16x2 I2C LCD Display**.

The project reads the current date and time from the DS3231 RTC module and displays it on the LCD.

---

## 📌 Project Overview

The **DS3231 Real-Time Clock (RTC)** module is used to keep accurate date and time information.

Unlike software-based timing, the RTC has a backup battery that allows it to continue keeping time even when the ESP32 is powered off.

Communication between the ESP32 and DS3231 is done using the **I2C protocol**. The LCD also uses I2C. The Arduino `Wire` library is used for I2C communication, while Adafruit's `RTClib` provides the DS3231 interface. 0

---

## 🎯 Features

- ⏰ Real-time clock
- 📅 Date display
- 🕐 Time display
- 🔋 Battery-backed time keeping
- 📟 16x2 I2C LCD display
- 🔌 ESP32 I2C communication
- 📡 DS3231 RTC module
- 🧩 Simple Arduino IDE project

---

## 🛠️ Components Required

| Component | Quantity |
|---|---:|
| ESP32 Development Board | 1 |
| DS3231 RTC Module | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |
| CR2032 Battery | 1 |

---

## 🔌 Circuit Connections

### DS3231 → ESP32

| DS3231 Pin | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

ESP32 commonly uses GPIO 21 for SDA and GPIO 22 for SCL for I2C communication. 1

### 16x2 I2C LCD → ESP32

| LCD Pin | ESP32 |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

Both the RTC and LCD share the same I2C SDA/SCL lines.

---

## 🔄 How It Works


        ┌─────────────────┐
        │      ESP32      │
        │                 │
        │ SDA → GPIO 21   │
        │ SCL → GPIO 22   │
        └───────┬─────────┘
                │
          I2C Communication
          ┌─────┴─────┐
          │           │
     ┌────▼────┐ ┌────▼────┐
     │ DS3231  │ │  LCD    │
     │   RTC   │ │ 16x2    │
     └─────────┘ └─────────┘
     
The DS3231 provides the current date and time.
The ESP32 reads the information using:
DateTime now = rtc.now();
and then sends the information to the LCD. The RTC_DS3231 class provides functions such as begin(), adjust(), lostPower(), and now(). �
Adafruit

📚 Required Libraries
Install the following library through:
Arduino IDE → Library Manager
RTClib

Search for:
RTClib
Install RTClib by Adafruit.
The library supports DS3231 RTC modules and provides the RTC_DS3231 class. �
GitHub
Also required:
#include <Wire.h>
#include <RTClib.h>

💻 Arduino Code
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS3231 rtc;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(115200);

  // Start I2C
  Wire.begin(21, 22);

  // Start LCD
  lcd.init();
  lcd.backlight();

  // Start RTC
  if (!rtc.begin()) {

    Serial.println("RTC not found!");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RTC Not Found!");

    while (1);
  }

  // Check if RTC lost power
  if (rtc.lostPower()) {

    Serial.println("RTC lost power!");

    // Set RTC time from computer compile time
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RTC Clock");
  delay(2000);
}

void loop() {

  DateTime now = rtc.now();

  // Display Time
  lcd.clear();

  lcd.setCursor(0, 0);

  if (now.hour() < 10)
    lcd.print("0");

  lcd.print(now.hour());
  lcd.print(":");

  if (now.minute() < 10)
    lcd.print("0");

  lcd.print(now.minute());
  lcd.print(":");

  if (now.second() < 10)
    lcd.print("0");

  lcd.print(now.second());

  // Display Date
  lcd.setCursor(0, 1);

  lcd.print(now.day());
  lcd.print("/");

  lcd.print(now.month());
  lcd.print("/");

  lcd.print(now.year());

  // Serial Monitor
  Serial.print("Time: ");

  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  Serial.print("Date: ");

  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.println(now.year());

  delay(1000);
}

⚠️ Important

The line:
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
sets the RTC using the date and time when the sketch is compiled.
After the RTC has been correctly set, avoid running this line every boot if you want the RTC to retain its actual time. A common approach is to use it only when the RTC reports that it has lost power. �
Random Nerd Tutorials

🖥️ LCD Output

Example:
12:45:32
24/09/2026
The first row shows:
HH:MM:SS
The second row shows:
DD/MM/YYYY

🔋 RTC Battery
The DS3231 module normally uses a coin-cell battery to maintain the clock when the main ESP32 power is removed.
If the RTC loses power, the library can detect this using:
rtc.lostPower();
and the time can then be set again using rtc.adjust(). 
Adafruit

🧪 Serial Monitor
Set the Serial Monitor to:
115200 baud
Example output:
Time: 12:45:32
Date: 24/9/2026

Time: 12:45:33
Date: 24/9/2026

🧰 Troubleshooting
RTC Not Found
Check:
SDA → GPIO 21
SCL → GPIO 22
VCC → 3.3V
GND → GND
Also make sure the RTC battery is installed.
LCD Not Showing Text
Check the LCD I2C address.

Common addresses are:
0x27
0x3F
If 0x27 doesn't work, run an I2C scanner to find the correct address.
Time Is Incorrect
Set the RTC again using:
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
Then upload the program.

📂 Project Structure
ESP32-DS3231-RTC/
│
├── Code/
│   └── ESP32_DS3231_RTC.ino
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

🚀 Future Improvements
⏰ Alarm system
📅 Day of the week display
🌡️ DS3231 temperature monitoring
🔔 Buzzer alarm
🌐 NTP time synchronization
📱 Web-based clock
📊 IoT time monitoring
⏱️ Digital stopwatch
🕐 12/24-hour format
🧠 What I Learned

Through this project, I learned:
ESP32 I2C communication
DS3231 RTC operation
LCD I2C communication
Date and time handling
Arduino libraries
Battery-backed time keeping
Reading sensor/module data
Displaying real-time information

🔧 Technologies
ESP32
Arduino IDE
C/C++
I2C
DS3231 RTC
16x2 I2C LCD
RTClib
👨‍💻 Author

Sasidu-Tech
BICT Student | Networking | Cyber Security | IoT Developer
GitHub:
https://github.com/Sasidu-Tech⁠

📜 License
This project is licensed under the MIT License.
⭐ If you found this project useful, consider giving the repository a star!

