#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include "DHT.h"

//8핀이 CLK
//9핀이 DAT
//10핀이 RST
ThreeWire myWire(9,8,10); // DAT, CLK, RST

class DHT dht {DHT(A0, 11, 6)};

enum PINS
{
  RGB_RED = 2U,
  RGB_GREEN,
  RGB_BLUE,
  BUZZER,
  WATER_SENSOR,
  PIR_SENSOR,
};

//RTC 라이브러리 생성
RtcDS1302<ThreeWire> Rtc(myWire);

void setup () 
{
  Serial.begin(115200UL);
  //컴파일 시점의 날짜(__DATE__)와 시간(__TIME__)을 시리얼모니터에 표시
  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);
  Serial1.begin(9600UL);
  pinMode(PIR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(WATER_SENSOR, OUTPUT);
  dht.begin();
  //RTC 모듈 라이브러리 시작
  Rtc.Begin();

  //RTCDateTime 클래스 생성(컴파일된 시간으로 설정)
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();
  
  //RTC모듈에 쓰기 금지 모드인지 확인
  if (Rtc.GetIsWriteProtected())
  {
    Serial.println("RTC was write protected, enabling writing now");
    //쓰기 금지 모드이면 해제
    Rtc.SetIsWriteProtected(false);
  }
    
  //RTC 모듈이 동작중이 아니라면
  if (!Rtc.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    // 시작해라!!!
    Rtc.SetIsRunning(true);
  }

  // RTC 모듈의 현재 시간 얻기
  RtcDateTime now = Rtc.GetDateTime();

  //RTC 모듈하고 위에 만든 RTC클래스(컴파일된 시간을 가지고 있는)와 비교해서
  //RTC 시간이 더 늦다면.. 
  if (now < compiled) 
  {
    //RTC가 컴파일 시간보다 느려!(시간을 갱신한다.)
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    //컴파일 시간을 RTC 모듈에 적용
    Rtc.SetDateTime(compiled);
  }
  //RTC 모듈이 컴파일한 시간보다 빠르다면
  else if (now > compiled) 
  {
    //RTC가 캄파일 시간보다 더 새것이다(그치 이래야지!!!)
    Serial.println("RTC is newer than compile time. (this is expected)");
  }
  //RTC와 컴파일한 시간이 같다면.
  else if (now == compiled) 
  {
    //RTC와 컴파일 시간이 같다. (그..그럴이가... 뭐 그래도 오케!)
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
}

void loop () 
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  String command {Serial1.readString()};
  //RTC 모듈의 현재 시간 얻기
  RtcDateTime now = Rtc.GetDateTime();

  //시리얼 모니터에 출력
  printDateTime(now);
  //줄 바꿈.
  Serial.println();
  if(temperature < 26)
  {
    Serial1.print(F("온도 : "));
    Serial1.print(temperature);
    Serial1.print(" , ");
    Serial1.print(F("습도 : "));
    Serial1.println(humidity);
    Serial1.println(F("Check closing the door"));
    Serial.print(F("Temperature : "));
    Serial.print(temperature);
    Serial.print(" , ");
    Serial.print(F("Humidity : "));
    Serial.println(humidity);
    Serial.println(F("Check closing the door"));
    delay(300UL);
    if(digitalRead(PIR_SENSOR))
    {
      Serial.println(F("enemy is detected..."));
      Serial.println(F("check the site ..."));
      Serial1.println(F("enemy is detected..."));
      Serial1.println(F("check the site ..."));
      Serial.println(F("BUZZER_ON"));
      Serial1.println(F("BUZZER_ON"));
      digitalWrite(BUZZER, HIGH);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
    }
    else if (command == "buzzer_on")
    {
      digitalWrite(BUZZER, HIGH);
      Serial.println(F("BUZZER_ON"));
      Serial1.println(F("BUZZER_ON"));
    }
    else if (command == "buzzer_off")
    {
      digitalWrite(BUZZER, LOW);
      Serial.println(F("BUZZER_OFF"));
      Serial1.println(F("BUZZER_OFF"));
    }
  }
  else
  {
    Serial1.print(F("온도 : "));
    Serial1.print(temperature);
    Serial1.print(" , ");
    Serial1.print(F("습도 : "));
    Serial1.println(humidity);
    Serial.print(F("Temperature : "));
    Serial.print(temperature);
    Serial.print(" , ");
    Serial.print(F("Humidity : "));
    Serial.println(humidity);
    delay(300UL);
    if(digitalRead(PIR_SENSOR))
    {
      Serial.println(F("enemy is detected..."));
      Serial.println(F("check the site ..."));
      Serial1.println(F("enemy is detected..."));
      Serial1.println(F("check the site ..."));
      Serial.println(F("BUZZER_ON"));
      Serial1.println(F("BUZZER_ON"));
      digitalWrite(BUZZER, HIGH);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
      digitalWrite(RGB_RED,HIGH);
      delay(100UL);
      digitalWrite(RGB_RED,LOW);
      delay(100UL);
    }
    else if (command == "buzzer_on")
    {
      digitalWrite(BUZZER, HIGH);
      Serial.println(F("BUZZER_ON"));
      Serial1.println(F("BUZZER_ON"));
    }
    else if (command == "buzzer_off")
    {
      digitalWrite(BUZZER, LOW);
      Serial.println(F("BUZZER_OFF"));
      Serial1.println(F("BUZZER_OFF"));
    }
  }
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

//시리얼 모니터에 날짜 시간 표시하는 함수
void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];

  snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
  Serial.print(datestring);
}