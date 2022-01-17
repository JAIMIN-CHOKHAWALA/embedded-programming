/*
 * pattern-16.cpp
 *
 * Created: 06-10-2021 16:10:21
 * Author : JAIMIN
 */ 

#include <avr/io.h>

bool isAdjecentExists (uint8_t bits) {
	return (bits & (bits >> 1));
}

int main(void) {
	// setup
	DDRA = 0xD2;
	PINA = 0x2D;
	int temp;
	
	while (1) {
		PORTA = isAdjecentExists(!PINA) ? 0xD2 : 0x00;
    }
}

