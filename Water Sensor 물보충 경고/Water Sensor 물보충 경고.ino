// const uint_8 WATER_SENSOR = 9U;
enum PINS                                               //배열과 비슷하다.         //C++에서 적극 권장.     // 상수화 작업.
{
  WATER_SENSOR = 9U,                                   //enum의 경우, 를 사용한다.
  LED_PIN                                             //자동으로 10U로 저장된다.
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT);                    //(PINS.WATER_SENSOR, INPUT);  라고 써도 된다.
  pinMode(LED_PIN, OUTPUT);                       // 자동으로 LED_PIN이 3번으로 정렬 된다.
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(WATER_SENSOR) == LOW)          //if(!digitalRead(WATER_SENSOR) not 의 개념 //if(not digitalRead(WATER_SENSOR)) not 의 개념
  {
    for (int i = 0 ; i < 5; ++i)
    {
      Serial.println(F("Water Please !!"));
      digitalWrite(LED_PIN, HIGH);
      delay(250UL);
      digitalWrite(LED_PIN, LOW);
      delay(250UL);
    }
  }
  else 
  {
  Serial.println(F("flood"));                 // 디버깅 코드 logger[로거]라고 한다. 화면상에서만 보이는것.
  }
}
