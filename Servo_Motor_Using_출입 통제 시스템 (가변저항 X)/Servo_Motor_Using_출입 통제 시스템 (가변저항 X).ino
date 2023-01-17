#include <Servo.h>                                       // < > = 기본 설치 코드

class Servo servo = Servo();

const uint8_t VR_PIN = A13;
const uint8_t SERVO_PIN = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  servo.attach(SERVO_PIN);                                         //pinMode 설정
  pinMode(VR_PIN, INPUT);
  delay(100UL);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.availaber())
{
  const int angle = Serial.parseint();
  Servo.Write(angel);
}
}
