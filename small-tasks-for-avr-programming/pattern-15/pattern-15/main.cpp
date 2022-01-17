/*
 * pattern-15.cpp
 *
 * Created: 07-10-2021 13:42:49
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <stdint.h>

int main(void) {
	// setup
	DDRA = 0x12;
	PORTA = ~0x12;
	
    while (1) {
		PORTA = ((PINA << 1) ^ (PINA >> 1));		
    }
}

