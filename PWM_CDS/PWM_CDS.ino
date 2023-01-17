const uint8_t CDS_SENSOR {A7};

enum
{
  RGB_BLUE = 2U,
  RGB_GREEN,
  RGB_RED,
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(CDS_SENSOR, INPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  delay(100UL);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(CDS_SENSOR));
  delay(100);
  if(analogRead(CDS_SENSOR) >= 700)
  {
    digitalWrite(RGB_BLUE, HIGH);
    digitalWrite(RGB_RED, LOW);
    digitalWrite(RGB_GREEN, LOW);
  }
  else if(analogRead(CDS_SENSOR) >= 600)
  {
    digitalWrite(RGB_BLUE, LOW);
    digitalWrite(RGB_GREEN, HIGH);
    digitalWrite(RGB_RED, LOW);
  }
  else if(analogRead(CDS_SENSOR) >= 500)
  {
    digitalWrite(RGB_BLUE, LOW);
    digitalWrite(RGB_GREEN, LOW);
    digitalWrite(RGB_RED, HIGH);
  }
  else
  {
    digitalWrite(RGB_BLUE, LOW);
    digitalWrite(RGB_GREEN, LOW);
    digitalWrite(RGB_RED, LOW);
  }
}
