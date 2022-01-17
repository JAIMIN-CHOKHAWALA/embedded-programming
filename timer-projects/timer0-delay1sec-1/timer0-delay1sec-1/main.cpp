/*
 * timer0-delay1sec-1.cpp
 *
 * Created: 11-10-2021 15:59:25
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))



void loopDelay () {
	static unsigned int i = 60;
	if (i == 0) return;
	TCCR0A = 0x05;
	TCNT0 = 0x01;
	while (TIFR0 & (1 << TOV0) == 0);
	TCCR0A = 0;
	TIFR0 = 0x01;	
	--i;
	loopDelay();
}

int main(void) {
	DDRA |= MASK(0);
	PORTA = 0x00;
	
    while (1) {
		PORTA ^= MASK(0);
		loopDelay();
    }
}

