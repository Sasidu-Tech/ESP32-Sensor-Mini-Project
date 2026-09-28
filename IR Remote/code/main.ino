#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define S_PIN 34

unsigned long command;

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);
  IrReceiver.begin(S_PIN);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("IR REMOTE!");

  delay(800);

  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:

  

  lcd.setCursor(0, 0);
  lcd.print("Command ---->");

  if(IrReceiver.decode()){

    command = IrReceiver.decodedIRData.decodedRawData;
  

    lcd.setCursor(0, 1);
    lcd.print(command);

    IrReceiver.resume();
  }

}
