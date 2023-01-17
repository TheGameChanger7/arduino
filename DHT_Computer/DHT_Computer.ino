#include "DHT.h"

// class DHT dht {DHT(A0, 11, 6)}; // 생성자 호출  //객체를 생성하면 자동으로 생성자 호출
DHT * dht = new DHT(A0, 11); // 파이썬, 자바의 경우에 원래는 이런형태로 사용.

void setup() {
  // put your setup code here, to run once:
  dht -> begin();       // 파이썬 자바 형태로 사용해 보자. 포인터로 받을것이므로 화살표 사용.
  Serial.begin(115200UL); // Serial 유선통신
  Serial.begin(9600UL); // 블루투스 통신
//  dht.begin();
//  delete dht; // new를 사용하여 포인터를 생성했으면 삭제도 해줘야한다. 하지만 계속 사용할 것이므로 궂이 사용하지 않을 것이다.
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht -> readTemperature();
  float humidity = dht -> readHumidity();
  Serial1.print(F("온도 : "));
  Serial1.println(temperature);
  Serial1.print(F("습도 : "));
  Serial1.println(humidity);
  // 컴퓨터에 던져줘야 합니다.
  Serial.print(temperature);
  Serial.print(",");           //CSV 데이터 타입 comma seperated value // TSV 데이터 타입 tap seperated value 
  Serial.println(humidity);
  // Serial.println(temperature + " , " + humidity);
  delay(500UL);
}
