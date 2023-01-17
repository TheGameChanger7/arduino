#include "DHT.h"

class DHT dht {DHT(A0, 11, 6)}; // 생성자 호출  //객체를 생성하면 자동으로 생성자 호출

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL); // Serial 유선통신
  Serial1.begin(9600UL); // 블루투스 통신
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
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
