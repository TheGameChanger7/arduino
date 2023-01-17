//#include <RobotIRremote.h>
//#include <RobotIRremoteInt.h>
#include <RobotIRremoteTools.h>

const uint8_t LED_PIN_1 {53} ;
const uint8_t LED_PIN_2 {51} ;
const uint8_t LED_PIN_3 {49} ;
const uint8_t LED_PIN_4 {47} ;
const uint8_t LED_PIN_5 {45} ;
const uint8_t LED_PIN_6 {43} ;
const uint8_t LED_PIN_7 {41} ;
const uint8_t LED_PIN_8 {39} ;
enum PINS                                               //배열과 비슷하다.         //C++에서 적극 권장.
{
  WATER_SENSOR = 9U,                                   //enum의 경우, 를 사용한다.
  RGB_RED,                                              //자동으로 10U로 저장된다.
  RGB_BLUE,                                             //자동으로 11U로 저장된다.
  RGB_GREEN,                                            //자동으로 12U로 저장된다.
  RELAY_SWITCH = 3U,
  BUZZER = 22U,                             
};

void setup() {
// put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT); 
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RELAY_SWITCH, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  beginIRremote(); // IR Receiver 시작 (초기화) // 라이브러리 헤더파일에 있는 함수 호출.
}

void loop() {
  // put your main code here, to run repeatedly:
  while(IRrecived())
  {
    uint32_t KEY {getIRresult()}; // 수신값이 넘어온다. unsigned long 값을 받아오므로 uint32_t 사용    
    resumeIRremote(); //Next Received value;
    if(KEY == -1)
    {
      break;
    }
    Serial.println(KEY, HEX); // 헥사코드를 사용. //16진수 이므로 0x라고 사용 해야 한다.
    switch(KEY)               // 함수밖에서는 Hiding되기 때문에 switch문은 같은 라인으로 들어와야 한다.
    {
    case 0xFF6897:                       //0번
      digitalWrite(RELAY_SWITCH, LOW);
      delay(250UL);
      digitalWrite(RGB_RED, LOW);
      digitalWrite(RGB_BLUE, LOW);
      digitalWrite(RGB_GREEN, LOW);
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(BUZZER, LOW);
      break;
    case 0xFF30CF:                       //1번
      digitalWrite(RELAY_SWITCH, HIGH);
      digitalWrite(RGB_RED, HIGH);
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(BUZZER, HIGH);
      delay(250UL);
      digitalWrite(RGB_RED, LOW);
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(BUZZER, LOW);
      delay(250UL);
      digitalWrite(RGB_BLUE, HIGH);
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(BUZZER, HIGH);
      delay(250UL);
      digitalWrite(RGB_BLUE, LOW);
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(BUZZER, LOW);
      delay(250UL);
      digitalWrite(RGB_GREEN, HIGH);
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(BUZZER, HIGH);
      delay(250UL);
      digitalWrite(RGB_GREEN, LOW);
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(BUZZER, LOW);
      delay(250UL);
      break;
    }
  } 
}
