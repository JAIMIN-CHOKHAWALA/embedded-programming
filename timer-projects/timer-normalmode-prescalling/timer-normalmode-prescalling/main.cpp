/*
 * timer-normalmode-prescalling.cpp
 *
 * Created: 09-10-2021 13:20:47
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#define MASK(k) ((unsigned char)(1 << k))

void delay1Sec () {
	TCCR0 = 0x02; // 8 bit p-s
	TCNT0 = 0xC0; 
	while (TIFR & (1 << TOV0) == 0);
	TCCR0 = 0;
	TIFR = 0x01;
}

int main(void) {
	DDRB |= MASK(3);
	
    while (1) {
		PORTB ^= MASK(3);
		delay1Sec();
    }
}

