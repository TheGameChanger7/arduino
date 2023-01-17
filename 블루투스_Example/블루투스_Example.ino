#include "DHT.h"

class DHT dht {DHT(A0, 11, 6)};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL); // Serial 유선통신
  Serial1.begin(9600UL); // Bluetooth
  dht.begin(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // if(dht.read())
  // {
  //   if(Serial1.available() > 0) //블루투스 연결되었다면
  //   {
  //     float temperature = dht.readTemperature();
  //     Serial1.print(F("온도는 : "));  //블루투스
  //     Serial1.println(temperature);
  //     Serial.print(F("Temperature : "));  //시리얼
  //     Serial.println(temperature);  //시리얼
  //   }
  // }
  // if(Serial1.available() > 0) //블루투스 연결되었다면
  //   {
  //     float temperature = dht.readTemperature();
  //     Serial1.print(F("온도는 : "));  //블루투스
  //     Serial1.println(temperature);
  //     Serial.print(F("Temperature : "));  //시리얼
  //     Serial.println(temperature);  //시리얼
  //   }
  // delay(500UL);

  float temperature = dht.readTemperature();
  Serial1.print(F("온도는 : "));  //블루투스
  Serial1.println(temperature);
  Serial.print(F("Temperature : "));  //시리얼
  Serial.println(temperature);  //시리얼
  delay(500UL);  
}
