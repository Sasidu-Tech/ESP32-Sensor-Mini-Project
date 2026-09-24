#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Wire.begin(21, 22); //SDA , SCL

  lcd.init();
  lcd.backlight();

  if(!rtc.begin()){
    lcd.setCursor(0, 0);
    lcd.print("RTC NOT FOUNFD!");
    while(1);
  }

  lcd.clear();

  if(rtc.lostPower()){
    lcd.setCursor(0, 0);
    lcd.print("Setting Time...");

  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));  
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  DateTime now = rtc.now();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RTC CLOCK");

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("D: ");
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  lcd.setCursor(0, 1);
  lcd.print("T: ");
  if(now.hour()<10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");


  if(now.minute()<10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");


  if(now.second()<10) lcd.print("0");
  lcd.print(now.second());

  delay(1000);

}
