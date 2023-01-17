enum
{
  RGB_GREEN = 2U,
  RGB_BLUE,
  RGB_RED,
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600UL);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)                // 값이 있을때만 읽어서 진행 하도록하기 위해서.
  {
    String str1 = Serial.readString();      // 스트링으로 읽는게 가장 좋다.
    int value1 = str1.toInt();               // 문자열을 정수형으로 바꾸는 메소드
    Serial.print(F("You have entered : "));
    Serial.println(str1);
    analogWrite(RGB_RED, value1);
  }

}
