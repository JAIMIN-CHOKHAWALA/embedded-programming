/*
 * SPC-capslock-Tx.cpp
 *
 * Created: 20-10-2021 15:34:57
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define MASK(k) ((unsigned char)(1 << k))

unsigned char state = 0;

void __init__ () {
	UCSR0B = (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0L = 0x33;
}

void toggle_light () {
	if (PINC) {
		state=1;
		} else {
		if(state==1){
			PORTD^=1;
			state=0;
		}
	}	
}

int main(void) {
	DDRC = 0x00;
	DDRB=0XFF;
	DDRD = 0xFF;
	//DDRE |= MASK(1);
	//PORTC |= MASK(0);
	PORTC=0x01;
 	
	__init__();
	
  while (1) { // 0000 0000
	  toggle_light();
	
	  while (!(UCSR0A & (1 << UDRE0)));	 
	  // PORTB=UDR0;
	  UDR0 = PORTD;
  }
  
  return 0;
}

