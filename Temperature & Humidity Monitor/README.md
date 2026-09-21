🌡️ ESP32 DHT11 + I2C LCD Temperature & Humidity Monitor

![ESP32 Wi-Fi Scanner](images/Temp%20%26%20Hum%20(3).jpeg)

A simple beginner-friendly ESP32 project that reads temperature and humidity using a DHT11 sensor and displays the values on a 16x2 I2C LCD.

This project is useful for learning basic ESP32 sensor interfacing, I2C communication, and LCD display control.

---

📌 Project Overview

The ESP32 reads environmental data from the DHT11 sensor and displays:

- 🌡️ Temperature in Celsius (°C)
- 💧 Humidity in Percentage (%)

The readings are displayed on the 16x2 I2C LCD and also printed in the Serial Monitor.

---

🧰 Components Required

Component| Quantity
ESP32 Dev Module| 1
DHT11 Temperature & Humidity Sensor| 1
16x2 I2C LCD| 1
Jumper Wires| Several
USB Cable| 1

---

🔌 Wiring

DHT11 → ESP32

DHT11 Pin| ESP32
VCC| 3.3V
DATA / SIGNAL| GPIO 27
GND| GND

16x2 I2C LCD → ESP32

LCD Pin| ESP32
VCC| 5V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

📊 Pin Summary

ESP32
│
├── GPIO 27 → DHT11 DATA
│
├── GPIO 21 → LCD SDA
├── GPIO 22 → LCD SCL
│
├── 3.3V → DHT11 VCC
├── 5V   → LCD VCC
└── GND  → DHT11 GND + LCD GND

---

📦 Required Arduino Libraries

Install these libraries from:

Arduino IDE → Library Manager

- DHT sensor library
- Adafruit Unified Sensor
- LiquidCrystal I2C

---

💻 Arduino Code

#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHT_PIN 27
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  dht.begin();

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("ESP32 DHT11");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  delay(2000);
  lcd.clear();
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 Read Error!");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    
    delay(2000);
    return;
  }

  // Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("--------------------");

  // LCD Temperature
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C");

  // LCD Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  delay(2000);
}

---

🖥️ Example LCD Output

┌────────────────┐
│Temp: 28.5 °C   │
│Humidity: 62.3% │
└────────────────┘

---

📟 Serial Monitor

Set the Serial Monitor baud rate to:

115200

Example:

Temperature: 28.5 °C
Humidity: 62.3 %
--------------------
Temperature: 28.6 °C
Humidity: 61.9 %
--------------------

---

⚙️ How It Works

        DHT11
          │
          │ Temperature
          │ Humidity
          ↓
        ESP32
          │
          │ I2C
          ↓
     16x2 LCD
          │
          ↓
   Temperature
   Humidity

1. DHT11 measures the surrounding temperature and humidity.
2. ESP32 reads the sensor values through GPIO 27.
3. ESP32 processes the readings.
4. LCD receives data through I2C using GPIO 21 and GPIO 22.
5. Temperature and humidity are displayed on the LCD.
6. The same values are printed to the Serial Monitor.

---

🎯 Features

- ✅ ESP32 based
- ✅ DHT11 temperature measurement
- ✅ DHT11 humidity measurement
- ✅ 16x2 I2C LCD display
- ✅ Real-time readings
- ✅ Serial Monitor output
- ✅ Simple jumper-wire connection
- ✅ Beginner friendly
- ✅ Low-cost IoT mini project

---

🚀 Future Improvements

This project can later be upgraded with:

- 🌐 ESP32 Web Dashboard
- 📱 Mobile monitoring
- ☁️ Firebase data logging
- 📊 Temperature & humidity graphs
- 🔔 High-temperature alert
- 📧 Notification system
- 💾 Data logging
- 📡 Wi-Fi based remote monitoring

---

👨‍💻 Author

Sasidu-Tech

Built using ESP32 + DHT11 + 16x2 I2C LCD.

---

📄 License

This project is released under the MIT License.

---

⭐ If you found this project useful, consider giving the repository a Star!
