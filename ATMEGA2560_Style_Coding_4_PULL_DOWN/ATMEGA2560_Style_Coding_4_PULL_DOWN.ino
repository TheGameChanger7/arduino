#define F_cpu 16000000UL
#include <avr/io.h>

int main()
{
  //pinMode(13, OUTPUT);
  DDRB |= 0x80; // 0b1000_0000 PB7              //아두이노 13번핀 켜기 // OUTPUT으로 바꿔주는 작업.
  DDRE &= ~(0x20); // &= ~(0b0010_0000) PE5            //아두이노  3번핀 끄기 // 안써도 된다 기본셋팅이 INPUT이기 때문
  //for
  while(true)
  {
    uint8_t state = PINE & 0x20; //0b0010_0000  // PINE라고 쓰면 핀이 연결된곳만 1로 변한다. 따라서 0b0010_0000이랑 0x20이랑 and 연산.
    if(state)
    {
      PORTB |= 0x80; //0b1000_0000
    }
    else
    {
      PORTB &= ~0x80; //0b0000_0000
    }
  }
}