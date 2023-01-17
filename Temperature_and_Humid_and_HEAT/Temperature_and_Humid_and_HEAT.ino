#include "DHT.h"              //레인지 잘 파악하기.

const uint8_t LED_PIN_1 {53} ;
const uint8_t LED_PIN_2 {51} ;
const uint8_t LED_PIN_3 {49} ;
const uint8_t LED_PIN_4 {47} ;
const uint8_t LED_PIN_5 {45} ;
const uint8_t LED_PIN_6 {43} ;
const uint8_t LED_PIN_7 {41} ;
const uint8_t LED_PIN_8 {39} ;

enum PINS
{
  DHT11_PIN = A8,
  RELAY_SWITCH = 3U,
};

class DHT dht {DHT(DHT11_PIN, 11, 6)}; // DHT 센서 객체 생성. (DHT.h를 확인하고 사용), 6은 default값이라서 안써도 된다.
                //(핀번호, 버전, 디폴트값)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);                    //정밀 센서들은 초기화가 필수이다.
  dht.begin();                              //센서 초기화     //객체 안의 함수이기 때문에 dht.을 해야한다.
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  pinMode(RELAY_SWITCH, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature {dht.readTemperature()};                //온도             //유니폼 이니셜라이져.
  Serial.print(F("Temperature : "));
  Serial.println(temperature);
  float humidity {dht.readHumidity()};                      //습도             //객체 내 함수는 .을 반드시 사용
  Serial.print(F("Humidity : "));
  Serial.println(humidity);                                 //new line
  float heat {dht.computeHeatIndex(temperature, humidity)}; //열체크
  Serial.print(F("Heat : "));                               //equal line
  Serial.println(heat);                                     //new line
  delay(500UL);
  if(28.0f <= temperature)                                  // 큰 값부터 순차적으로 내려가는 식으로 코딩하는게 좋다.
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH); 
  }
  else if(27.0f <= temperature && temperature < 28.0f) 
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else if(26.0f <= temperature && temperature < 27.0f) 
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else if(25.0f <= temperature && temperature < 26.0f) 
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else if(24.0f <= temperature && temperature < 25.0f) 
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else if(23.0f <= temperature && temperature < 24.0f) 
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else if(22.0f <= temperature && temperature < 23.0f) 
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else if(21.0f <= temperature && temperature < 22.0f)    //정확한 실수값 float type
  {
    digitalWrite(RELAY_SWITCH, HIGH);
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
  else 
  {
    digitalWrite(RELAY_SWITCH, LOW);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW); 
  }
}
