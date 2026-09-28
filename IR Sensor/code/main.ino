#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define S_PIN 15

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  pinMode(S_PIN, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("IR SENSOR!");

  delay(800);

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.clear();

  int sensorState = digitalRead(S_PIN);

  if(sensorState == LOW){

    lcd.setCursor(0, 0);
    lcd.print("OBJECT DETECTED");

  }else{
    lcd.setCursor(0, 0);
    lcd.print("NO OBJECT");


}

}
