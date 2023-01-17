#include <LiquidCrystal_I2C.h>

class LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);

uint8_t mario[] =
{
  0b00100,
  0b01110,
  0b00100,
  0b11111,
  0b00100,
  0b00100,
  0b01010,
  0b01010,
};

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print(F("LCD init..."));
  delay(1000UL);
  lcd.clear();
  lcd.home();
  lcd.createChar(0u, mario);       //lcd.write(0)             
}
static int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  
  for(int i = 0; i < 16; ++i)
  {
    if(i == 15)
    {
      for(int j = 15; j >= 0; --j)
      {
        lcd.setCursor(j,0);
        lcd.write(uint8_t(0));         //픽셀 하나 사용할때 쓴다. 
        delay(500UL);
        lcd.home();
        lcd.print("                ");
      }
    }
    else
    {
      lcd.setCursor(i,0);
      lcd.write(uint8_t(0));         //픽셀 하나 사용할때 쓴다. 
      delay(500UL);
      lcd.home();
      lcd.print("                ");
    }
  }
}
