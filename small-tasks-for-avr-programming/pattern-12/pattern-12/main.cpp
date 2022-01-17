/*
 * pattern-12.cpp
 *
 * Created: 06-10-2021 14:18:27
 * Author : JAIMIN
 */ 

#include <avr/io.h>


int main(void) {
	// setup
	DDRA = 0xAA;
	PINA = 0x55;
	PORTB = 0x00;
	
    while (1) {
		PORTA = ~PINA << 1;
    }
}

