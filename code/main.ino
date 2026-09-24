#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define D_pin 15
#define A_pin 27

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  pinMode(D_pin, INPUT);
  pinMode(A_pin, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

  bool sensorState = digitalRead(D_pin);
  int  sensorValue = analogRead(A_pin);

  lcd.setCursor(0, 0);
  lcd.print("VALUE: ");
  lcd.print(sensorValue);




  if(sensorState == HIGH){
    lcd.setCursor(0, 1);
    lcd.print("BODY TUCHED");

  }else{
    
    
    lcd.setCursor(0, 1);
    lcd.print("NO TUCHED");
  }

 
 delay(500);

}
