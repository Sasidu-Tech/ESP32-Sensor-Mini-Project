## 🌡️ ESP32 DS18B20 Digital Temperature Monitor

## 🎥 Demo

[![Watch Demo on YouTube](https://img.shields.io/badge/Watch%20Demo-YouTube-red?logo=youtube)](https://youtu.be/Ex5ItYg6ZzY?si=3z7nE2GiZXV8Ldog)

<table>
  <tr>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/DS18B20%20Digital%20Temperature%20Sensor%20Module/images/%20DS18B20%20Digital%20Temperature%20Sensor%20(1).jpeg" width="400">
    </td>
    <td align="center">
      <img src="https://github.com/Sasidu-Tech/ESP32-Sensor-Mini-Project/blob/main/DS18B20%20Digital%20Temperature%20Sensor%20Module/images/%20DS18B20%20Digital%20Temperature%20Sensor%20(3).jpeg" alt="ESP32 Wi-Fi Scanner Demo" width="400">
    </td>
  </tr>
</table>


A simple and practical digital temperature monitoring system built using an ESP32, DS18B20 Digital Temperature Sensor, and 16×2 I2C LCD Display.

The DS18B20 measures the temperature and sends the digital data to the ESP32 using the 1-Wire communication protocol. The measured temperature is displayed on the LCD and Serial Monitor.

📌 Project Overview

This project demonstrates how to interface a DS18B20 digital temperature sensor with ESP32 and display the measured temperature on a 16×2 I2C LCD.

✨ Features
🌡️ Digital temperature measurement
📡 DS18B20 1-Wire communication
🖥️ 16×2 I2C LCD display
🔄 Real-time temperature updates
⚡ ESP32-based system
🚨 Sensor disconnection detection
📟 Serial Monitor temperature output
🧰 Components Required
Component	Quantity
ESP32 DevKit	1
DS18B20 Digital Temperature Sensor Module	1
16×2 I2C LCD	1
Jumper Wires	As required
Breadboard	1

Note: If your DS18B20 module does not already contain a pull-up resistor, use a 4.7kΩ resistor between DATA and 3.3V.

🔌 Wiring
DS18B20 → ESP32
DS18B20	ESP32
VCC	3.3V
GND	GND
DATA / DQ	GPIO 4
16×2 I2C LCD → ESP32
LCD	ESP32
VCC	5V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
📐 Connection Diagram
             ┌─────────────────────┐
             │       ESP32         │
             │                     │
             │ GPIO 4  ────────────┼──── DATA
             │ 3.3V    ────────────┼──── VCC
             │ GND     ────────────┼──── GND
             │                     │
             │ GPIO 21 ────────────┼──── SDA
             │ GPIO 22 ────────────┼──── SCL
             │ 5V      ────────────┼──── VCC
             │ GND     ────────────┼──── GND
             └─────────────────────┘
                    │
                    │
          ┌─────────┴─────────┐
          │                   │
     DS18B20 Sensor       16x2 I2C LCD
📚 Required Libraries

Install the following libraries through Arduino IDE → Library Manager:

OneWire
DallasTemperature
LiquidCrystal I2C
💻 Arduino Code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
#define LCD_ADDRESS 0x27

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  Serial.begin(115200);

  sensors.begin();

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("ESP32 TEMP");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  delay(2000);
  lcd.clear();
}

void loop() {

  sensors.requestTemperatures();

  float temperature = sensors.getTempCByIndex(0);

  if (temperature == DEVICE_DISCONNECTED_C) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");

    Serial.println("DS18B20 disconnected!");

  } else {

    lcd.setCursor(0, 0);
    lcd.print("Temperature:");

    lcd.setCursor(0, 1);
    lcd.print(temperature, 2);
    lcd.print((char)223);
    lcd.print("C    ");

    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" C");
  }

  delay(1000);
}
🖥️ LCD Display

Example output:

Temperature:
27.35°C

The temperature updates approximately every 1 second.

📟 Serial Monitor

Set the Serial Monitor baud rate to:

115200

Example:

Temperature: 27.35 C
Temperature: 27.42 C
Temperature: 27.50 C
⚠️ Troubleshooting
LCD is blank

Try changing:

#define LCD_ADDRESS 0x27

to:

#define LCD_ADDRESS 0x3F

Some I2C LCD modules use 0x3F instead of 0x27.

DS18B20 shows Sensor Error

Check:

DATA → GPIO 4
VCC → 3.3V
GND → GND
4.7kΩ pull-up resistor if required
Sensor module orientation
🧠 What I Learned

Through this project, I learned:

Interfacing DS18B20 with ESP32
Digital temperature measurement
1-Wire communication
I2C LCD interfacing
Using Arduino libraries
Real-time sensor data display
Basic sensor error handling
🚀 Future Improvements

Possible upgrades:

📱 ESP32 Web Temperature Dashboard
📊 Temperature data logging
☁️ IoT cloud monitoring
📈 Live temperature graph
🔔 High-temperature alarm
📲 Mobile monitoring
💾 SD card temperature logging
📸 Project

Project: ESP32 DS18B20 Digital Temperature Monitor
Platform: ESP32
Sensor: DS18B20
Display: 16×2 I2C LCD
Programming: Arduino C/C++

👨‍💻 Author

Sasidu Wishshanka

BICT Undergraduate | Embedded Systems | IoT | Robotics | Networking & Cybersecurity

🔗 Connect With Me
GitHub: Sasidu-Tech
LinkedIn: Sasidu Wishshanka
📄 License

This project is licensed under the MIT License.

© 2026 Sasidu-Tech
