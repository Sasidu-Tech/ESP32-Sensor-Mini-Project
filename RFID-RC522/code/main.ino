#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 5
#define RST_PIN 4

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  // LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("RFID SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("Scan Card...");
  delay(2000);

  // RFID
  SPI.begin(18, 19, 23, 5);
  rfid.PCD_Init();

  Serial.println("RFID Ready");
}

void loop() {

  // Check for new card
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Display UID
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Card Detected");

  Serial.print("UID: ");

  lcd.setCursor(0, 1);

  for (byte i = 0; i < rfid.uid.size; i++) {

    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
    }

    Serial.print(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1) {
      Serial.print(":");
    }

    if (i < 4) {
      lcd.print(rfid.uid.uidByte[i], HEX);
      if (i < rfid.uid.size - 1) {
        lcd.print(":");
      }
    }
  }

  Serial.println();

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan Card...");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}