//비트 단위로 접근해야 한다.
const uint8_t PIN_NUMBER = 8;    // 가독성 향상
const uint8_t PINS[PIN_NUMBER] = {22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U}; //배열의 이름은 복수로 사용한다.
const uint8_t FNDS[10] =
{
 0b11111100, /*0 REGISTER*/
 0b01100000, /*1*/
 0b11011010, /*2*/
};
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  for(int i = 0; i < PIN_NUMBER; ++i)   //for문 안에서도 로컬변수로 사용된다.
  {
    pinMode(PINS[i], OUTPUT);
  }
  /*C++의 문법
  for(auto && i : PINS)         // auto = const uint8_t를 가져올 것이다.
  {
    pinMode(i, OUTPUT);
  }
  */ 
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(bitRead(FNDS[0], 7));    bitRead함수를 이용해서 비트를 뒤에서 부터 읽어 온다.
  for(int j = 0; j < 10; ++j)
  {
    for(int i = 0; i < 8; ++i)
    {
      if(bitRead(FNDS[j], i))
      {
        digitalWrite(PINS[7-i], HIGH);
      }
      else
      {
        digitalWrite(PINS[7-i], LOW);
      }
    }
  }
  delay(1000UL);
}
