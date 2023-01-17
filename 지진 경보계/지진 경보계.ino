const uint8_t EARTHQUAKE_SW = 19U;              // 인터럽트 4번핀에 연결
static volatile uint16_t counting {0u};        // volatile 최적화 하지마라.
enum PINS
{
  LED_RED = 3U,
  LED_GREEN,
  LED_BLUE,
  LED_YELLOW,
  BUZZER,
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(EARTHQUAKE_SW, INPUT_PULLUP);
  attachInterrupt(4, earthQuake, CHANGE);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void EQ()
{
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(300UL);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(BUZZER, LOW);
  delay(300UL);
}

void earthQuake()
{
  if(counting >= 1000) counting = 0;
  ++counting;
  Serial.println("moving detected.");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(F("counting: "));
  Serial.println(counting);
  if(counting > 100) {
  Serial.println("EarthQuake");
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(300UL);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(BUZZER, LOW);
  delay(300UL);
  }
  delay(300UL);


  // 주석 처리하기 컨트롤 슬래쉬
  // if(digitalRead(EARTHQUAKE_SW) == HIGH)
  // {
  //   Serial.println(digitalRead(EARTHQUAKE_SW));
  // }

  // else
  // {
  //   Serial.println(digitalRead(EARTHQUAKE_SW));
  // }
  //delay(10UL);
}
