#include <LiquidCrystal_I2C.h>

class LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);      // (주소값, 가로, 세로)

void setup() {
  // put your setup code here, to run once:
  lcd.init(); // LCD 초기화
  lcd.backlight(); // 백라이트를 켜주세요.
  lcd.setCursor(0,0); // 디스플레이 커서 위치를 설정해주세요.
  String str1 = "Hello World";
  lcd.print(str1);
  lcd.setCursor(0,1);
  String str2 = "My initial SZ";
  lcd.print(str2);

}

void loop() {
  // put your main code here, to run repeatedly:

}
