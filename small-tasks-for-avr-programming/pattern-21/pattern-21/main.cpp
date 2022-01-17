/*
 * pattern-21.cpp
 *
 * Created: 08-10-2021 13:09:48
 * Author : JAIMIN
 */ 

#include <avr/io.h>

int main(void) {
	DDRC = 0xAA;
	PORTC = 0x55;
	
    while (1) {
		PORTC = (~PINC >> 1) ^ (~PINC << 1);
    }
}

