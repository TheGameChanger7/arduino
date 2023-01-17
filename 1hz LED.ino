//#include <Arduino.h>                                  //원래는 적어 줘야하는데 버전업 되서 필요없다.

const uint8_t LED_PIN {13U};                            // unsigned int 8bit : 1byte = 0 ~ 255의 범위. // 13U == 13unsigned를 의미한다.
// 8bit == 1byte : 핀번호가 255개 이하 이니까 궂이 const int를 사용할 필요가 없다. // 아두이노 환경에서는 const int == 16bit 이다.
//13번핀은 LED_BUILTIN이라는 특수한 이름을 가진다. 따라서 LED_PIN 대신에 LED_BUILTIN을 써도 된다.
void setup() {
  // put your setup code here, to run once: //
  Serial.begin(115200UL);                               //Serial는 객체이다. 따라서.을 이용해서 함수 begin에 접근 //UL = unsigned long // 115200/10을해서 1초당 11520개의 문자를 보낸다.
  pinMode(LED_PIN, OUTPUT);                             //아두이노는 기본적으로 INPUT상태 //OUTPUT은 컴퓨터로 받아온 전기를 밖으로 내보내겠다. //쉴드를 내리겠다는 의미 쉴드를 내리지않으면 저항이 상당히 강한데 OUTPUT이면 쉴드를 내리게되어 저항이 줄어들게된다.
  digitalWrite(LED_PIN, LOW);                           //불이 꺼짐.
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);                          
  Serial.println(F("LED ON"));                          //F = 플래쉬 램에다가 사용하라는 의미 상당히 빠르다. 반복문은 F에 넣는게 최적화이다. 전역공간 비슷한곳에 넣어두는것.
  delay(500);
                                                        // 보통은 S램(코드를 저장해놓는곳)에 저장되어있다가 사라졌다가 생겼다 반복하는데 F램은 사라지지 않는다.                                                        
  digitalWrite(LED_PIN, LOW);
  Serial.println(F("LED OFF"));
  delay(500);
}
