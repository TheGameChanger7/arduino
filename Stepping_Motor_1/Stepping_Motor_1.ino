#include <Stepper.h>
int step_per_revolution = 2048;            //한바퀴 돌때 LOW, HIGH가 2048번 반복이 필요하다.
class Stepper stepping(step_per_revolution, 27, 25, 26, 24);     // (2048번의 회전, IN4번핀, IN2번핀, IN3번핀, IN1번핀)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  stepping.setSpeed(14L);                           // 14RPM (1분당 14번 회전속도)
}

void loop() {
  // put your main code here, to run repeatedly:
  stepping.step(step_per_revolution);
  delay(1000UL);
  // stepping.step(-step_per_revolution);              // 반대로 회전.
  // delay(1000UL);
}
