#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

int step_per_revolution = 2048;            //한바퀴 돌때 LOW, HIGH가 2048번 반복이 필요하다.
class Stepper stepping(step_per_revolution, 43, 41, 42, 40);     // (2048번의 회전, 43번핀, 41번핀, 42번핀, 40번핀)
class LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);      // (주소값, 가로, 세로)

void setup() {
  // put your setup code here, to run once:
  lcd.init(); // LCD 초기화
  lcd.backlight(); // 백라이트를 켜주세요.
  Serial.begin(115200UL);
  stepping.setSpeed(14L);                           // 14RPM (1분당 14번 회전속도)
}

void loop() {
  // put your main code here, to run repeatedly:
  stepping.step(step_per_revolution);  
  lcd.setCursor(0,0); // 디스플레이 커서 위치를 설정해주세요.
  String str1 = "FORWARD ";
  lcd.print(str1);
  delay(1000UL);
  stepping.step(-step_per_revolution);              // 반대로 회전.
  lcd.setCursor(0,0);
  String str2 = "BACKWARD";
  lcd.print(str2);
  delay(1000UL);
}
