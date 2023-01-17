#include "DHT.h"

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  pinMode(PIR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(WATER_SENSOR, OUTPUT);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  String command {Serial1.readString()};
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



  // String command {Serial1.readString()};
  // if (command == "buzzer_on")
  // {
  //   digitalWrite(BUZZER, HIGH);
  //   Serial1.println(F("BUZZER_ON"));
  // }
  // else if (command == "buzzer_off")
  // {
  //   digitalWrite(BUZZER, LOW);
  //   Serial1.println(F("BUZZER_OFF"));
  // }
  //   if(digitalRead(PIR_SENSOR))
  // {
  //   Serial.println(F("enemy is detected..."));
  //   Serial.println(F("check the site ..."));
  //   digitalWrite(BUZZER, HIGH);   
  // }