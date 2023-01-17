const uint8_t PULL_UP = 13U;
const uint8_t RGB_RED = 4U;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(PULL_UP, INPUT);                      //PULL UP은 INPUT
  pinMode(RGB_RED, OUTPUT);
  delay(100UL);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("HELLO");
  if(digitalRead(PULL_UP))
  {
    Serial.println("1");
    digitalWrite(RGB_RED, LOW);
    delay(100UL);
  }
  else
  {
    Serial.println("0");
    digitalWrite(RGB_RED, HIGH);
    delay(100UL);
  }
}
