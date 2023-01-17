const uint8_t VR_PIN {A0}; // A0 = 54 = 0x36
const uint8_t LED_PIN_1 {53} ;
const uint8_t LED_PIN_2 {51} ;
const uint8_t LED_PIN_3 {49} ;
const uint8_t LED_PIN_4 {47} ;
const uint8_t LED_PIN_5 {45} ;
const uint8_t LED_PIN_6 {43} ;
const uint8_t LED_PIN_7 {41} ;
const uint8_t LED_PIN_8 {39} ; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL); //시리얼 창에서 값을 확인
  pinMode(VR_PIN, INPUT); // 안해도 되지만 그냥 했다. 기본이 INPUT모드이기 때문이다. // analog핀은 일반적으로 INPUT모드만 사용한다.
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t value = (uint16_t)analogRead(VR_PIN);     // 2**10비트 = 1024 이기 때문에 uint8_t = 255라서 안됨. 따라서 uint16_t를 사용하거나 int를 사용
  uint8_t mapped_value {(uint8_t)(map(value, 0, 1023, 0, 8))};  // map함수 이용 // 0 ~ 1023을 0 ~ 7로 바꾸어 주는것.
  Serial.println(mapped_value);                   // 변화가 많은 값은 F사용하면 안된다. 너무 많은 공간을 차지하기 때문에.
  delay(100UL);                                // 변화가 너무 민감하면 딜레이값을 올려라!

  
  if( mapped_value == 0 )
  {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }
  else if( mapped_value == 1 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW); 
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }
  else if( mapped_value == 2 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }
  else if( mapped_value == 3 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }  
  else if( mapped_value == 4 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }
  else if( mapped_value == 5 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }  
  else if( mapped_value == 6 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }
  else if( mapped_value == 7 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, LOW);
    delay(100UL);
  }
  else if( mapped_value == 8 )
  {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    delay(100UL);
  }
}

//uint16_t value = (uint16_t)analogRead(VR_PIN);
//uint16_t value { static_cast<uint16_t>(analogRead(VR_PIN)) };
//uint16_t value { (uint16_t)(analogRead(VR_PIN)) }
//알고리듬 짜기 8가지 경우의수 = 나누기 8을해서 나머지 0,1,2,3,4,5,6,7를 이용한다.
//Map 함수 이용