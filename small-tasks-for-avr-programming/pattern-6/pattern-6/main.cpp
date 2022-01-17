/*
 * pattern-6.cpp
 *
 * Created: 05-10-2021 16:35:05
 * Author : JAIMIN
 */ 

#include <avr/io.h>


int main(void) {
	// setup
	DDRB = 0xFF;
	DDRA = 0xFF;
	PINA = 0xFF;	
	PORTB = 0x00;
	
    while (1) {
		PORTB = PINA;
		
    }
}

