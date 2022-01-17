/*
 * pattern-9.cpp
 *
 * Created: 06-10-2021 12:35:59
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>


int main(void) {
	// setup
	DDRA = 0xFF;
	uint8_t i = 0;
	PORTA = 0x00;
	
    while (1) {
		PORTA |= (1 << i); ++i;
		_delay_ms(300);
		
		if (i == 8) {
			while (PORTA != 0) {
				PORTA = PORTA >> 1;
				_delay_ms(300);
			}
			i = 0;
		}
		
    }

}

