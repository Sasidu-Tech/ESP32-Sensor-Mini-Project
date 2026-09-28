#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


#define A_pin 34
#define D_pin 15

void setup() {
  // put your setup code here, to run once:

  Wire.begin(21, 22);
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();


  pinMode(A_pin, INPUT);
  pinMode(D_pin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture!");
  delay(1000);


  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:


  int sensorValue = analogRead(A_pin);
  int sensorState = digitalRead(D_pin);

  if(sensorState == LOW){

    lcd.setCursor(0, 0);
    lcd.print("Soil Wet");

    lcd.setCursor(0, 1);
    lcd.print("VALUE: ");
    lcd.print(sensorValue);


  }else{

    lcd.setCursor(0, 0);
    lcd.print("Soil Dry");

    lcd.setCursor(0, 1);
    lcd.print("VALUE: ");
    lcd.print(sensorValue);

  }

}
