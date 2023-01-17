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

//const uint8_t RECV_PIN {6U}; // IR_PIN == 6
//class IRrecv irrecv(RECV_PIN); // 클래스 생성자 IRrecv, 객체는 irrecv 
//class decode_result result;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  beginIRremote(); // IR Receiver 시작 (초기화) // 라이브러리 헤더파일에 있는 함수 호출.
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IRrecived())
  {
    uint32_t KEY {getIRresult()}; // 수신값이 넘어온다. unsigned long 값을 받아오므로 uint32_t 사용    
    resumeIRremote(); //Next Received value;
    Serial.println(KEY, HEX); // 헥사코드를 사용. //16진수 이므로 0x라고 사용 해야 한다.
    switch(KEY)               // 함수밖에서는 Hiding되기 때문에 switch문은 같은 라인으로 들어와야 한다.
    {
      case 0xFF6897:                       //0번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF30CF:                       //1번
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF18E7:                       //2번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF7A85:                       //3번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF10EF:                       //4번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF38C7:                       //5번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF5AA5:                       //6번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF42BD:                        //7번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      break;
      case 0xFF4AB5:                        //8번
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, HIGH);
      break;
      case 0xFF52AD:                        //9번
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      break;
      default:
      Serial.println(F("You pressed the wrong number"));
    }
  }
}
