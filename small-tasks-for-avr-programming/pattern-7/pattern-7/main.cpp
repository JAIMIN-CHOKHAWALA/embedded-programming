/*
 * pattern-7.cpp
 *
 * Created: 05-10-2021 17:34:22
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main(void) {
	// setup
	DDRA = 0xFF;
	uint8_t i = 0;
	DDRB = 0xFF;
	uint8_t j = 3;
		
    while (1) {
		// if (i > 3) i = 0;
		i = i > 3 ? 0 : i;
		PORTA = (1 << i) | (1 << (7 - i)); ++i;
		_delay_ms(1000);
		
		// if (j < 0) j = 3;
		/*
		j = j < 0 ? 3 : j;
		PORTB = (1 << j) | (1 << (7 - j)); --j;
		_delay_ms(1000);
		*/
    }
}

