// #include <Arduino.h>                 //          
#define F_CPU 16000000UL               //아두이노는 수정자(Crystal)를 통해 Clock수를 조절한다. // 컴퓨터 CPU와 아두이노의 Clock수를 맞추어 주는 작업.
#include <avr/io.h>                    //ATMEGA를 AVR이라고 한다.  // 즉 AVR Programming
#include <util/delay.h>

int main(const int argc, const char* argv[])
{
  DDRB = 0x80; //0b1000_0000 == PIN13을 OUTPUT상태로 전환 //공책정리 참고
  for(;;)
  {
    PORTB &= ~0x80; // ~를 붙여서 비트 반전 즉 LED 끄기     //PORTB = PORTB & ~0x80          //비트 연산자 사용
    _delay_ms(1000UL);
    PORTB |= 0x80; // LED 켜기                             //PORTB = PORTB | 0x80           //비트 연산자 사용
    _delay_ms(1000UL);
  }
  return 0;
}
