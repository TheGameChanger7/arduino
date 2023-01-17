enum Joystick
{
  VR_X = A6,
  VR_Y = A7,
  SW = 31U,       // 버튼 스위치
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  pinMode(LED_BUILTIN, OUTPUT); // 13 == LED_BUILTIN
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  uint16_t vr_x = analogRead(VR_X);
  Serial.print(F("VR_X : "));
  Serial1.print(F("VR_X : "));
  Serial.println(vr_x);
  Serial1.println(vr_x);

  uint16_t vr_y = analogRead(VR_Y);
  Serial.print(F("VR_Y : "));
  Serial1.print(F("VR_Y : "));
  Serial.println(vr_y);
  Serial1.println(vr_y);

  delay(100UL);

  uint8_t sw_value = digitalRead(SW);
  Serial.print(F("SW : "));
  Serial1.print(F("SW : "));
  Serial.println(sw_value);
  Serial1.println(sw_value);

  // if(Serial1.available() > 0)
  // {
  //   String command {Serial1.readString()};
  //   if (command == "led_on")                // command.equals("led_on") 가 더 좋은 표현
  //   {
  //     digitalWrite(LED_BUILTIN, HIGH);
  //     Serial1.println(F("LED ON"));         //ack신호 무전에서 정상적으로 들어오는것을 체크하는 역할
  //   }
  //   else if (command == "led_off")
  //   {
  //     digitalWrite(LED_BUILTIN, LOW);
  //     Serial1.println(F("LED OFF"));
  //   }
  //   else
  //   {
  //     Serial.println(F("You pressed wrong input value"));
  //   }
  // }
  // delay(100UL);
}
