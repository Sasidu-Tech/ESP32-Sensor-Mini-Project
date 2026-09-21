#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 27
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if(isnan(humidity) || isnan(temperature)){
    lcd.setCursor(0, 0);
    lcd.print("Faild Read!");
    return;
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("H :");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("T :");
  lcd.print(temperature);
  lcd.write(223);
  lcd.print("C");

  delay(1000);

}
