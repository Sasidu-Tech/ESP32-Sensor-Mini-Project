#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SOUND_PIN 27
#define LED_PIN 26

bool lightState = false;
bool lastSound = LOW;

unsigned long lastTrigger = 0;
const unsigned long cooldown = 500;

void setup() {

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  Serial.begin(115200);

  pinMode(SOUND_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Sound Light");

  lcd.setCursor(0, 1);
  lcd.print("System Ready");

  delay(1000);

  lcd.clear();
}

void loop() {

  bool sound = digitalRead(SOUND_PIN);

  // New sound detected
  if (sound == HIGH && lastSound == LOW) {

    // Ignore very fast repeated signals
    if (millis() - lastTrigger > cooldown) {

      lightState = !lightState;

      digitalWrite(LED_PIN, lightState);

      if (lightState) {
        lcd.setCursor(0, 0);
        lcd.print("SOUND:LIGHT ON");
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SOUND:LIGHT OFF");
      }

      lastTrigger = millis();
    }
  }

  lastSound = sound;
}
