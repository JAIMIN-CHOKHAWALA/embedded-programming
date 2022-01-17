/*
 * pattern-10-optimized.cpp
 *
 * Created: 06-10-2021 13:41:19
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
	uint8_t i = 0;
	int number = log10(PINA) / log10(2);
    while (1) {
		
		PORTB = (1 << i); ++i;
		for (int i = 0; i < number; ++i) {
			_delay_ms(100);
		}
		
    }
}

