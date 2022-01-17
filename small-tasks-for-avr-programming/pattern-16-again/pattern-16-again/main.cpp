/*
 * pattern-16-again.cpp
 *
 * Created: 08-10-2021 12:21:11
 * Author : JAIMIN
 */ 

#include <avr/io.h>


int main(void) {
	// setup
	DDRA = 0x92;
	DDRB = 0xA4;
	// PORTA = 0x6D;
	//PORTB = 0x5B;
	
    while (1) {		
		PORTA = (~PINA << 1) ^ (~PINA >> 1) ^ (~PINB << 7);
		PORTB = (~PINB << 1) ^ (~PINB >> 1);
    }
}

