enum PINS {
  RGB_BLUE = 2U,
  RGB_GREEN,
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
  if(Serial.available() > 0) {
    String str = Serial.readString();
    if(str == "RED_ON\n") {
      digitalWrite(RGB_RED, HIGH);
    } else if (str == "RED_OFF\n") {
      digitalWrite(RGB_RED, LOW);  
    } else if (str == "GREEN_ON\n") {
      digitalWrite(RGB_GREEN, HIGH);
    }
    else if (str == "GREEN_OFF\n")
    {
      digitalWrite(RGB_GREEN, LOW);
    }
    else if (str == "BLUE_ON\n")
    {
      digitalWrite(RGB_BLUE, HIGH);
    }
    else digitalWrite(RGB_BLUE, LOW);    
  }

}
