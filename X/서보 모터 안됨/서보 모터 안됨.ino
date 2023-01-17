const uint8_t SERVO_pin = 8U;

void setup() {
  Serial.begin(115200UL);
}

void loop() {
  int i;
  for (i = 0; i < 256; i = i + 8) {
    analogWrite(SERVO_pin, i);
    delay(100UL);
    Serial.println(i);
  }
  delay(1000UL);
  for (i = 255; i >= 0; i = i - 8) {
    analogWrite(SERVO_pin, i);
    delay(100UL);
    Serial.println(i);
  }
  delay(100UL);
}