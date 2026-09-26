#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


#define A_pin 34

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();


  pinMode(A_pin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Water Level");
  delay(1000);




}

void loop() {
  // put your main code here, to run repeatedly:


  int  sensorValue = analogRead(A_pin);

  lcd.clear();

 
  
    lcd.setCursor(0, 0);
    lcd.print("VALUE: ");
    lcd.print(sensorValue);


 
 delay(800);

}
