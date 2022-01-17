/*
 * pattern-14.cpp
 *
 * Created: 06-10-2021 15:30:42
 * Author : JAIMIN
 */ 

#include <avr/io.h>


int main(void) {
	// setup
	DDRA = 0xAA;
	PINA = 0x55;
	// PORTA = 0x55;
	
		
    while (1) {
		PORTA = ~PINA << 1;
		
    }
}

