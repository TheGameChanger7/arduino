// const uint_8 WATER_SENSOR = 9U;
enum PINS                                               //배열과 비슷하다.         //C++에서 적극 권장.
{
  WATER_SENSOR = 9U,                                   //enum의 경우, 를 사용한다.
  RGB_RED,                                              //자동으로 10U로 저장된다.
  RGB_BLUE,                                             //자동으로 11U로 저장된다.
  RGB_GREEN,                                            //자동으로 12U로 저장된다.
  RELAY_SWITCH = 3U,                                          
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT);                    //(PINS.WATER_SENSOR, INPUT);  라고 써도 된다.
  pinMode(RGB_RED, OUTPUT);                       //
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RELAY_SWITCH, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(WATER_SENSOR) == HIGH)          //if(!digitalRead(WATER_SENSOR) not 의 개념 //if(not digitalRead(WATER_SENSOR)) not 의 개념
  { 
    digitalWrite(RELAY_SWITCH, HIGH);
    for (int i = 0 ; i < 5; ++i)
    {
      Serial.println(F("Warning flood !!"));
      digitalWrite(RGB_RED, HIGH);
      delay(250UL);
      digitalWrite(RGB_RED, LOW);
      delay(250UL);
      digitalWrite(RGB_BLUE, HIGH);
      delay(250UL);
      digitalWrite(RGB_BLUE, LOW);
      delay(250UL);
      digitalWrite(RGB_GREEN, HIGH);
      delay(250UL);
      digitalWrite(RGB_GREEN, LOW);
      delay(250UL);
    }
  }
  else 
  {
  Serial.println(F("No flood"));                 // 디버깅 코드 logger[로거]라고 한다. 화면상에서만 보이는것.
  digitalWrite(RELAY_SWITCH, LOW);
  }
}