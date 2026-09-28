#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED 15
#define S_PIN 14

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(S_PIN, INPUT);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Light Cup!");

  delay(800);

  lcd.clear();



}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorState = digitalRead(S_PIN);

    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);

  if(sensorState == HIGH){

    digitalWrite(LED, HIGH);
    lcd.print("MOTION DETECTED!");
  }
  else{

    digitalWrite(LED, LOW);
    lcd.print("NO MOTION!");
  }

 

  

}
