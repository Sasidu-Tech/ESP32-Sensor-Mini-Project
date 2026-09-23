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