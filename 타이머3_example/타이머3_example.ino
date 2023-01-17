// 타이머란 0 ~ 9999999를 세다가 정해진 오버플로우를 넘어가는 순간 플래그가 생겨서 인터럽트에 걸리는 것이다.
#include <TimerThree.h>

const uint8_t PIR_PIN = 10U;
// const uint8_t LED_BUILTIN = 10U;       //불가능한 표현이다. LED_BUILTIN = 13번핀이라는 고유명사 이다.

void detect_person();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500UL);
  Timer3.initialize(250000); // 2^16 = 0 ~ 65535 // microsecond 10^-6 // 매 0.25초 가 될때 PIR 센서가 감지
  Timer3.attachInterrupt(detect_person); // call back 함수를 만든다. 이름은 detect_person
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void detect_person()
{
  interrupts();                                          //인터럽트의 중복 방지
  if(digitalRead(PIR_PIN))
  {
    Serial.println(F("enemy is detected..."));
    Serial.println(F("check the site ..."));
    digitalWrite(LED_BUILTIN, HIGH);   
  }
  noInterrupts();                                       //인터럽트 중복 방지 해제
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);
  delay(100UL);
}
