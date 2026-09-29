#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// DS18B20 DATA pin
#define ONE_WIRE_BUS 4

// LCD I2C address
#define LCD_ADDRESS 0x27

// Create objects
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  Serial.begin(115200);

  // Start DS18B20
  sensors.begin();

  // Start I2C LCD
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

  // Request temperature
  sensors.requestTemperatures();

  // Read temperature in Celsius
  float temperature = sensors.getTempCByIndex(0);

  // Check sensor
  if (temperature == DEVICE_DISCONNECTED_C) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    
    Serial.println("DS18B20 disconnected!");

  } else {

    // LCD display
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");

    lcd.setCursor(0, 1);
    lcd.print(temperature, 2);
    lcd.print((char)223);
    lcd.print("C    ");

    // Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" °C");
  }

  delay(1000);
}