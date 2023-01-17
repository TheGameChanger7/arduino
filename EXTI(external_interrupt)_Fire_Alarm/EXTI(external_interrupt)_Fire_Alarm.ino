#include "DHT.h"

enum PINS
{
  TEMPER_PIN = A0,
  CDS_PIN = A7,
  RGB_BLUE = 2U,
  RGB_GREEN,
  RGB_RED,
  LED_RED = 11U,
  BUZZER = 52U,
  OFF_SW,
};

class DHT dht {DHT(TEMPER_PIN, 11, 6)}; // DHT 센서 객체 생성. (DHT.h를 확인하고 사용), 6은 default값이라서 안써도 된다.
                //(핀번호, 버전, 디폴트값)

void show_temperature();
void show_light();
void show_rgb();

void setup() {
  // put your setup code here, to run once:
  pinMode(TEMPER_PIN, INPUT);
  pinMode(CDS_PIN, INPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(OFF_SW, INPUT);
  Serial.begin(115200UL);
  dht.begin();                              //센서 초기화     //객체 안의 함수이기 때문에 dht.을 해야한다.
  attachInterrupt(2, alarm_fire, FALLING);                     // 21번핀은 interrupt2 이기때문에.   //화재 감지 센서 역할
  //4가지 MODE : RISING, FALLING, CHANGE, LOW
}

// callback
void alarm_fire()                                              // 인터럽트 함수는 최대한 짧게 사용하는게 좋다.  //
{
  Serial.println(F("Fire Fire Fire !!!"));
  // delay 절대 사용 금지 (interrupt는 H/W 방식이기 때문에)
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LED_RED, HIGH);
  //exit(1);                                      // 인터럽트에 비상정지를 사용하지 않을 경우 한번 왔다가 다른 프로그램은 바로 실행되어 버린다.
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(OFF_SW))       // PULL DOWN 스위치 이용.
  {
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED_RED, LOW);
    //Serial.println(F("문제가 해결되었습니다. !!!"));
  }
//delay(500UL);                    // interrupt의 부저 울리는 시간은 여기에 표현하면 된다.
  show_temperature();
  show_light();
  show_rgb();
}

void show_temperature()
{
  float temperature {dht.readTemperature()};                //온도             //유니폼 이니셜라이져.
  Serial.print(F("Temperature : "));
  Serial.println(temperature);
  float humidity {dht.readHumidity()};                      //습도             //객체 내 함수는 .을 반드시 사용
  Serial.print(F("Humidity : "));
  Serial.println(humidity);                                 //new line
  float heat {dht.computeHeatIndex(temperature, humidity)}; //열체크
  Serial.print(F("Heat : "));                               //equal line
  Serial.println(heat);                                     //new line  
}
void show_light()
{
  Serial.println(analogRead(CDS_PIN));
  delay(100);
  if(analogRead(CDS_PIN) >= 700)
  {
    digitalWrite(RGB_BLUE, HIGH);
    digitalWrite(RGB_RED, LOW);
    digitalWrite(RGB_GREEN, LOW);
  }
  else if(analogRead(CDS_PIN) >= 600)
  {
    digitalWrite(RGB_BLUE, LOW);
    digitalWrite(RGB_GREEN, HIGH);
    digitalWrite(RGB_RED, LOW);
  }
  else if(analogRead(CDS_PIN) >= 500)
  {
    digitalWrite(RGB_BLUE, LOW);
    digitalWrite(RGB_GREEN, LOW);
    digitalWrite(RGB_RED, HIGH);
  }
  else
  {
    digitalWrite(RGB_BLUE, LOW);
    digitalWrite(RGB_GREEN, LOW);
    digitalWrite(RGB_RED, LOW);
  }
  delay(300UL);
}
void show_rgb()
{
  digitalWrite(RGB_BLUE, HIGH);
  digitalWrite(RGB_RED, HIGH);
  digitalWrite(RGB_GREEN, HIGH);
  delay(300UL);
}