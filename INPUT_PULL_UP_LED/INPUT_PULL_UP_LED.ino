const uint8_t PULL_UP_SW_PIN = 12U;
const uint8_t RGB_BLUE {2U};

void setup() {
  // put your setup code here, to run once:
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(PULL_UP_SW_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t pin_value {digitalRead(PULL_UP_SW_PIN)};
  if(pin_value == HIGH)
  {
    digitalWrite(RGB_BLUE, HIGH);
  }
  else
  {
    digitalWrite(RGB_BLUE, LOW);
  }
  delay(10UL);
}
