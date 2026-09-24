🔥 ESP32 MQ-2 Gas Leak Detection System

📸 Project Preview
![ESP32 MQ-2 Gas Leak Detection](images/mq2-gas-detector.jpg)

A simple gas leakage detection project using an ESP32, MQ-2 Gas Sensor, and 16x2 I2C LCD Display.

The MQ-2 sensor continuously monitors the surrounding air. The ESP32 reads the sensor value and displays the gas status on the LCD.

🚀 Features

- 🔥 MQ-2 gas detection
- 📟 16x2 I2C LCD display
- ⚡ ESP32-based system
- 📊 Real-time sensor reading
- 🟢 Displays NO GAS LEAK when the value is below the threshold
- 🔴 Displays GAS LEAK! when the value exceeds the threshold
- 🖥️ Sensor value can also be monitored through the Serial Monitor

🧰 Components Required

Component| Quantity
ESP32 Dev Module| 1
MQ-2 Gas Sensor| 1
16x2 I2C LCD Display| 1
Jumper Wires| As required
Breadboard| 1
USB Cable| 1

🔌 Wiring

MQ-2 → ESP32

MQ-2 Pin| ESP32
VCC| 5V / VIN
GND| GND
AO| GPIO 34

I2C LCD → ESP32

LCD Pin| ESP32
VCC| 5V / VIN
GND| GND
SDA| GPIO 21
SCL| GPIO 22

«Note: GPIO 34 is an ADC input pin and is commonly used for analog MQ-2 readings on ESP32.»

⚙️ How It Works

        ┌──────────────┐
        │   MQ-2       │
        │ Gas Sensor   │
        └──────┬───────┘
               │
              AO
               │
               ▼
        ┌──────────────┐
        │    ESP32     │
        │              │
        │ Analog Read  │
        │ + Threshold  │
        └──────┬───────┘
               │
             I2C
               │
               ▼
        ┌──────────────┐
        │ 16x2 LCD     │
        │              │
        │ GAS LEAK!    │
        │      OR      │
        │ NO GAS LEAK  │
        └──────────────┘

Detection Logic

The ESP32 reads the analog output from the MQ-2 sensor.

if (gasValue > GAS_THRESHOLD) {
    // Gas detected
}
else {
    // No gas leak
}

The threshold should be adjusted according to the sensor and surrounding environment because MQ-2 readings vary between modules and conditions.

💻 Arduino Code

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MQ2_PIN 34

#define GAS_THRESHOLD 600

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("MQ-2 GAS");
  lcd.setCursor(0, 1);
  lcd.print("Warming Up...");

  delay(20000);

  lcd.clear();
}

void loop() {

  int gasValue = analogRead(MQ2_PIN);

  Serial.print("MQ-2 Value: ");
  Serial.println(gasValue);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Gas Value:");
  lcd.print(gasValue);

  lcd.setCursor(0, 1);

  if (gasValue > GAS_THRESHOLD) {

    lcd.print("GAS LEAK!");

    Serial.println("WARNING: GAS LEAK!");

  } else {

    lcd.print("NO GAS LEAK");

    Serial.println("Status: NO GAS LEAK");
  }

  delay(1000);
}

📚 Required Library

Install the following library from the Arduino IDE Library Manager:

LiquidCrystal I2C

🖥️ LCD Output

Normal Condition

Gas Value:350
NO GAS LEAK

Gas Detected

Gas Value:850
GAS LEAK!

⚠️ Important Notes

- The MQ-2 has an internal heating element and needs warm-up time before readings become more stable.
- "GAS_THRESHOLD" is an example value. You should observe your sensor's normal readings and adjust the threshold.
- This project is a prototype/educational gas detection system, not a certified safety device.
- Be careful when testing with gas or smoke.
- If your MQ-2 module's analog output can exceed the ESP32 ADC input range, use appropriate voltage scaling rather than connecting an over-voltage signal directly to the ESP32 ADC.

🛠️ Future Improvements

- 🔊 Add a buzzer alarm
- 🚨 Add red/green LEDs
- 📱 Send gas alerts through Wi-Fi
- 🌐 Create a web dashboard
- 📲 Send notifications using Telegram
- ☁️ Store gas readings in a cloud database

👨‍💻 Author

Sasidu Wishshanka

GitHub: "Sasidu-Tech" (https://github.com/Sasidu-Tech)

📄 License

This project is licensed under the MIT License.

---

⭐ If you found this project useful, feel free to star the repository!
