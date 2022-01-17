/*
 * timer0-normal-mode-no-prescalling.cpp
 *
 * Created: 09-10-20	21 12:50:22
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#define MASK(k) ((unsigned char)(1 << k))

void T0Delay () { // delay function generate 6.25 micro sec when called
	TCNT0 = 0x38; // 256-200 = 56 means every 0.1 sec as calculation
	TCCR0 = 0x01; // configure TIMER - normal mode | no pre-scalar
	while ((TIFR & (1 << TOV0)) == 0); // TOV0 is 0 while NOT flagged otherwise -> 1 | this line stops the code for 6.25 u-sec 
	TCCR0 = 0; // stop timer 0;
	TIFR = 0x01; // clear TOV0;
}

int main(void) {
	// setup
	DDRB |= MASK(3); // B 3rd pin as O/P
	while (1) {
		PORTB ^= MASK(3); // toggle PORTB 3rd pin every time this line runs
		
		T0Delay();
	}
}

