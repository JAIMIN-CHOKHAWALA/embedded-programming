/*
 * GccApplication1.c
 *
 * Created: 03-12-2021 03:53:12 PM
 * Author : JAIMIN CHOKHAWALA
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))
// 1 => 23 (violet), 2 => 22 (blue) | 3 => 24(orange), 4 => 20(unknown)

void acw (short int angle) {
    short int count = angle / 1.8;
    short int j = 0;
    for (int i = 0; i <= count; ++i) {
      if (j > 3) j = 0;
       PORTA = MASK(j);
      _delay_ms(20);
      ++j;
    }
 }

void cw (short int angle) {
    short int count = angle / 1.8;
    for (int i = 0; i <= count; ++i) {
      PORTA = MASK(3);
      _delay_ms(10);
      PORTA = MASK(2);
      _delay_ms(10);
      PORTA = MASK(1);
      _delay_ms(10);
      PORTA = MASK(0);
      _delay_ms(10);
    }
}


int main(void) { 
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(20, OUTPUT);


  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
  
  while (1){
    
  }
}
