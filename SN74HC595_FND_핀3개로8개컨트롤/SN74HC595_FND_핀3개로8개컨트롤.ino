#include <TimerThree.h>

const uint8_t SERIAL_PIN {26U};
const uint8_t LATCH_PIN {28U};
const uint8_t CLOCK_PIN {30U};
const uint8_t FNDS[10] =
{
0b01100001, //1 //(시리얼핀, 클락핀, MSB앞에부터/LSB 뒤에부터, 0b10101010 또는 B10101010)
0b11011011, //2
0b11110011, //3
0b01100111, //4
0b10110111, //5
0b10111111, //6
0b11100101, //7
0b11111111, //8
0b11100111, //9
0b11111101, //0
};

static int i = 0;                             // i를 전역변수로 사용하면 돌아간다.
void COUNTING();

void setup() {
  // put your setup code here, to run once:
  pinMode(SERIAL_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  Serial.begin(115200UL);
  Timer3.initialize(1000000); // 2^16 = 0 ~ 65535 // microsecond 10^-6 // 매 1초 가 될때 COUNTING
  Timer3.attachInterrupt(COUNTING); // call back 함수를 만든다. 이름은 COUNTING

}

void loop() {
  // put your main code here, to run repeatedly:
}

void COUNTING()
{
  interrupts();                                    // 인터럽트의 중복 방지
  {
    if (i % 10 == 0) i = 0;                        // 10이 되면 0으로 초기화 시키기
    digitalWrite(LATCH_PIN, LOW); // LATCH 잠그기 
    shiftOut(SERIAL_PIN, CLOCK_PIN, LSBFIRST, FNDS[i]); // (시리얼핀, 클락핀, MSB앞에부터/LSB 뒤에부터, 0b10101010 또는 B10101010)
    digitalWrite(LATCH_PIN, HIGH);  // LATCH 풀어서 한번에 다들어오게 하기.
    ++i;                                           // i 값을 증가시키기
  }
  noInterrupts();                                     // 인터럽트 중복 방지 해제
}





