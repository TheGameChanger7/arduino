#include "DHT.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  pinMode(LED_BUILTIN, OUTPUT); // 13 == LED_BUILTIN
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() > 0)
  {
    String command {Serial1.readString()};
    if (command == "led_on")                // command.equals("led_on") 가 더 좋은 표현
    {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial1.println(F("LED ON"));         //ack신호 무전에서 정상적으로 들어오는것을 체크하는 역할
    }
    else if (command == "led_off")
    {
      digitalWrite(LED_BUILTIN, LOW);
      Serial1.println(F("LED OFF"));
    }
    else
    {
      Serial.println(F("You pressed wrong input value"));
    }
  }
  delay(100UL);
}
