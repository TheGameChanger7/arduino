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
  RGB_BLUE = 2U,
  RGB_GREEN,
  RGB_RED,
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
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  
  for(int i = 0; i < PIN_NUMBER; ++i)   //for문 안에서도 로컬변수로 사용된다.
  {
    pinMode(PINS[i], OUTPUT);
  }
}
//함수 형태로 만들어보기

void seven_segment(uint8_t number)
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
  //nan
  if(dht.read())
  {
    float temperature {dht.readTemperature()};
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
      noTone(BUZZER);
      seven_segment(9);
      digitalWrite(RGB_GREEN, HIGH);
      delay(100UL);
      digitalWrite(RGB_GREEN, LOW);
    }
    else if(distance >= 80)
    {
      noTone(BUZZER);
      seven_segment(8);
      digitalWrite(RGB_BLUE, HIGH);
      delay(100UL);
      digitalWrite(RGB_BLUE, LOW);
    }
    else if(distance >= 70)
    {
      noTone(BUZZER);
      seven_segment(7);
      digitalWrite(RGB_BLUE, HIGH);
      delay(100UL);
      digitalWrite(RGB_BLUE, LOW);
    }
    else if(distance >= 60)
    {
      noTone(BUZZER);
      seven_segment(6);
      digitalWrite(RGB_BLUE, HIGH);
      delay(100UL);
      digitalWrite(RGB_BLUE, LOW);
    }
    else if(distance >= 50)
    {
      noTone(BUZZER);
      seven_segment(5);
      digitalWrite(RGB_BLUE, HIGH);
      delay(100UL);
      digitalWrite(RGB_BLUE, LOW);
    }
    else if(distance >= 40)
    {
      noTone(BUZZER);
      seven_segment(4);
      digitalWrite(RGB_BLUE, HIGH);
      delay(100UL);
      digitalWrite(RGB_BLUE, LOW);
    }
    else if(distance >= 30)
    {
      tone(BUZZER, 800);
      delay(80UL);
      noTone(BUZZER);
      delay(90UL);
      seven_segment(3);
      digitalWrite(RGB_RED, HIGH);
      delay(100UL);
      digitalWrite(RGB_RED, LOW);
    }
    else if(distance >= 20)
    {
      tone(BUZZER, 800);
      delay(80UL);
      noTone(BUZZER);
      delay(60UL);
      seven_segment(2);
      digitalWrite(RGB_RED, HIGH);
      delay(100UL);
      digitalWrite(RGB_RED, LOW);
    }
    else if(distance >= 10)
    {
      tone(BUZZER, 800);
      delay(80UL);
      noTone(BUZZER);
      delay(10UL);
      seven_segment(1);
      digitalWrite(RGB_RED, HIGH);
      delay(100UL);
      digitalWrite(RGB_RED, LOW);
    }
    else if(distance >= 0)
    {
      tone(BUZZER, 800);
      seven_segment(0);
      digitalWrite(RGB_RED, HIGH);
      delay(100UL);
      digitalWrite(RGB_RED, LOW);
    }
  }
}
