#include <LiquidCrystal_I2C.h>
#include "DHT.h"              //레인지 잘 파악하기.

enum PINS
{
  DHT11_PIN = A0,
};

class DHT dht {DHT(DHT11_PIN, 11, 6)};
class LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);     // (주소값, 가로, 세로)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.print("LCD init");
  delay(1000UL);
  lcd.clear();
  lcd.home();  //커서가 처음에 한번 자동으로 0,0으로 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  if(dht.read())  
  {
    float temperature {dht.readTemperature()};
    Serial.print(F("Temperature : "));
    Serial.println(temperature);
    lcd.print("Temperature");
    lcd.setCursor(0,1);
    lcd.print(temperature);
    delay(500UL);
    //lcd.clear;
    lcd.setCursor(0,1);
    lcd.print("                ");
  }
}
