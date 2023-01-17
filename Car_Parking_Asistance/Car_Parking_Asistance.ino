#include "DHT.h"
#include "HCSR04.h"

const uint8_t PIN_NUMBER = 8;    // 가독성 향상
const uint8_t PINS[PIN_NUMBER] = {22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U}; //배열의 이름은 복수로 사용한다.
const uint8_t FNDS[10] =
{
 0b11111101, /*0 REGISTER*/
 0b01100001, /*1*/
 0b11011011, /*2*/
 0b11110011, /*3*/
 0b01100111, /*4*/
 0b10110111, /*5*/
 0b10111111, /*6*/
 0b11100101, /*7*/
 0b11111111, /*8*/
 0b11100111, /*9*/
};

enum PINS         //유니폼 이니셜라이져를 사용하면 안된다.
{ 
  DHT_PIN = A0,
  ULTRA_SONIC_PIN_TR = 50U,
  ULTRA_SONIC_PIN_EC,
  BUZZER,
};
/** UltraSonicDistanceSensor(ULTRA_SONIC_PIN_TR, ULTRA_SONIC_PIN_EC) #생성자
    ultra_sonic 는 객체, 객체는, .(dot) 을 사용합니다.
    class UltraSonicDistanceSensor는 클래스 = 타입 int, double
**/
class UltraSonicDistanceSensor ultra_sonic = UltraSonicDistanceSensor(ULTRA_SONIC_PIN_TR, ULTRA_SONIC_PIN_EC); // 검정색 글씨가 클래스 빨간 글씨가 객체, 오른쪽 괄호안이 생성자
class DHT dht {DHT(DHT_PIN, 11)};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  dht.begin();
  pinMode(BUZZER, OUTPUT);
  for(int i = 0; i < PIN_NUMBER; ++i)   //for문 안에서도 로컬변수로 사용된다.
  {
    pinMode(PINS[i], OUTPUT);
  }
}
//함수 형태로 만들어보기
void seven_segment (uint8_t number)
{
  for(int i = 0; i < 8; ++i)
  {
    if(bitRead(FNDS[number], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
    {
      digitalWrite(PINS[7 - i], HIGH);
    }
    else
    {
      digitalWrite(PINS[7 - i], LOW);
    }
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature {dht.readTemperature()};
  //nan
  if(dht.read())
  {
    //Serial.print(F("Temperature : "));
    //Serial.println(temperature);
    float distance = ultra_sonic.measureDistanceCm(temperature);
    if(distance == -1.0f)
    {
      // Serial.println("something wrong.");
      return;
    }
    Serial.print(F("Distance : "));
    Serial.print(distance);
    Serial.println(F(" cm"));   
    delay(500UL);
/* 
    if(distance >= 90)
    {
      for(int j = 9;;)                       // 무슨 경우인가요???
      {
        for(int i = 0; i < 8; ++i)
        {
          if(bitRead(FNDS[j], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
          {
            digitalWrite(PINS[7 - i], HIGH);
          }
          else
          {
            digitalWrite(PINS[7 - i], LOW);
          }
        }
        delay(1000UL);
      }
    }
*/
    if(distance >= 90)
    {
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[9], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 80)
    {
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[8], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 70)
    {
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[7], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 60)
    {
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[6], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 50)
    {
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[5], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 40)
    {
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[4], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 30)
    {
      tone(BUZZER, 600);
      delay(100UL);
      noTone(BUZZER);
      delay(300UL);
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[3], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 20)
    {
      tone(BUZZER, 600);
      delay(100UL);
      noTone(BUZZER);
      delay(200UL);
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[2], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 10)
    {
      tone(BUZZER, 600);
      delay(100UL);
      noTone(BUZZER);
      delay(100UL);
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[1], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
    else if(distance >= 0)
    {
      tone(BUZZER, 600);
      for(int i = 0; i < 8; ++i)
      {
        if(bitRead(FNDS[0], i) == 1)       // 0이외의 값은 True로 인식하기 때문에 if(bitRead(FNDS[j], i))만 적어도 된다.
        {
          digitalWrite(PINS[7 - i], HIGH);
        }
        else
        {
          digitalWrite(PINS[7 - i], LOW);
        }
      }
    }
  }
}
