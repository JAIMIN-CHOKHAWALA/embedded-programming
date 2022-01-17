/*
 * pattern-11.cpp
 *
 * Created: 06-10-2021 14:00:45
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <math.h>

int main(void) {
	// setup
	DDRA = 0x00;
	DDRB = 0xFF;
	PORTB = 0xFF;
	PINA = 0xFF;
	uint8_t i = 0;
	
    while (1) {
		int number = log10(PINA) / log10(2);
		
		
		PORTB = (1 << i); ++i;
		for (int j = 0; j < number; ++j) {
			_delay_ms(1000);
		}
		PORTB = 0x00;
		
    }
}

