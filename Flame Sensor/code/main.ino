#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define A_PIN 34
#define D_PIN 15

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);

  pinMode(A_PIN,INPUT);
  pinMode(D_PIN,INPUT); 

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Flame Starting..");

  delay(1000);

  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorState = digitalRead(D_PIN);
  int sensorValue  = analogRead(A_PIN);

  if(sensorState == LOW){
    lcd.setCursor(0, 0);
    lcd.print("FIRE DETECTED");

    lcd.setCursor(0, 1);
    lcd.print("F-VALUE: ");
    lcd.print(sensorValue);
  }
  else{

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NO FIRE");

    lcd.setCursor(0, 1);
    lcd.print("F-VALUE: ");
    lcd.print(sensorValue);

  }

  delay(500);

}
