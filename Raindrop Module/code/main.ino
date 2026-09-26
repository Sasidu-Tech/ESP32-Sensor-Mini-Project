#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define D_pin 15
#define A_pin 34

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  pinMode(D_pin, INPUT);
  pinMode(A_pin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Raindrop Module");
  delay(1000);




}

void loop() {
  // put your main code here, to run repeatedly:

  bool sensorState = digitalRead(D_pin);
  int  sensorValue = analogRead(A_pin);

  lcd.clear();

  if(sensorState == LOW){
    lcd.setCursor(0, 0);
    lcd.print("RAINING");

    lcd.setCursor(0, 1);
    lcd.print("VALUE: ");
    lcd.print(sensorValue);

  }else{
    
    
    lcd.setCursor(0, 0);
    lcd.print("NO RAINING");

    lcd.setCursor(0, 1);
    lcd.print("VALUE: ");
    lcd.print(sensorValue);
  }

 
 delay(800);

}
