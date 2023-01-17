//워터 센서 이용 // 감지된경우 LCD창에 표시 + 스태핑모터로 와이퍼 작동시키기
//좌측 깜빡이 우측 깜빡이 넣기 

#include <LiquidCrystal_I2C.h>
#include "DHT.h"              //레인지 잘 파악하기.
#include <Stepper.h>

enum PINS
{
  DHT11_PIN = A0,
  WATER_SENSOR,
  RELAY_SWITCH = 5U,
  PULL_UP_SW_PIN,                                           
};

int step_per_revolution = 2048;            //한바퀴 돌때 LOW, HIGH가 2048번 반복이 필요하다.
class Stepper stepping(step_per_revolution, 43, 41, 42, 40);     // (2048번의 회전, 43번핀, 41번핀, 42번핀, 40번핀)
class DHT dht {DHT(DHT11_PIN, 11, 6)};
class LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);     // (주소값, 가로, 세로)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT);
  pinMode(RELAY_SWITCH, OUTPUT);
  pinMode(PULL_UP_SW_PIN, INPUT_PULLUP);
  stepping.setSpeed(14L);                           // 14RPM (1분당 14번 회전속도)
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
  if(digitalRead(WATER_SENSOR) == LOW)
  {
    if(dht.read())  
    {
      if(digitalRead(PULL_UP_SW_PIN) == LOW)
      {
        digitalWrite(RELAY_SWITCH, HIGH);
        delay(500UL);
        digitalWrite(RELAY_SWITCH, LOW);
        delay(500UL);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Emergency switch");
        lcd.setCursor(0,1);
        lcd.print("ON..............");     
      }
      else
      {
        float temperature {dht.readTemperature()};
        Serial.print(F("Temperature : "));
        Serial.println(temperature);
        lcd.setCursor(0,0);
        lcd.print("Temperature:");
        lcd.setCursor(12,0);
        lcd.print(temperature);
        delay(500UL);
        //lcd.clear();
        lcd.setCursor(12,0);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("Sunny days");
      }
    }
  }
  else
  {
    if(digitalRead(PULL_UP_SW_PIN) == LOW)
    {
      digitalWrite(RELAY_SWITCH, HIGH);
      delay(500UL);
      digitalWrite(RELAY_SWITCH, LOW);
      delay(500UL);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Emergency switch");
      lcd.setCursor(0,1);
      lcd.print("ON..............");     
    }    
    else
    {
      lcd.setCursor(0,0);
      lcd.print("It's Rainning");
      lcd.setCursor(0,1);
      lcd.print("Wiper On");
      delay(500UL);
      lcd.print("                ");
      stepping.step(-step_per_revolution);    
      delay(1000UL);
      stepping.step(-step_per_revolution);              // 반대로 회전.
      delay(1000UL);
    }
  }
}
