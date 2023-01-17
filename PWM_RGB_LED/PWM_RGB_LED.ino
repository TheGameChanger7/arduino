//가변저항을 이용해서 duty Cycle를 변화 시키는 작업.

const uint8_t VR_PIN = A13;
enum
{
  RGB_BLUE = 2U,
  RGB_GREEN,
  RGB_RED,
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(VR_PIN, INPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  delay(100UL);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t vr_value {analogRead(VR_PIN)};
  uint16_t mapped_value {map(vr_value, 0, 1023, 0, 255)};
  Serial.println(mapped_value);
  analogWrite(RGB_BLUE, mapped_value);
  analogWrite(RGB_GREEN, mapped_value);
  analogWrite(RGB_RED, mapped_value);
}
