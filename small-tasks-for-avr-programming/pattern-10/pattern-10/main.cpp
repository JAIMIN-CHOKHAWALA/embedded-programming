/*
 * pattern-10.cpp
 *
 * Created: 06-10-2021 12:54:33
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <cmath>

int main(void) {
    // setup
	DDRA = 0x00;
	DDRB = 0xFF;
	PINA = 0xFF;
	PORTB = 0x00;
	uint8_t i = 0;
	
	while (1) {
		switch (PINA) {
			case 0xFE:
				i = 0;
				while (i != 8) {
					PORTB = (1 << i); ++i;
					_delay_ms(100 * 1);
				}
				break;
			
			case 0xFD:
				i = 0;
				while (i != 8) {
					PORTB = (1 << i); ++i;
					_delay_ms(100 * 3);
				}
				break;
			
			case 0xFB:
				i = 0;
				while (i != 8) {
					PORTB = (1 << i); ++i;
					_delay_ms(100 * 5);
				}
				break;
			
			case 0xF7:
				i = 0;
				while (i != 8) {
					PORTB = (1 << i); ++i;
					_delay_ms(100 * 10);
				}
				break;
		}		
    }
}

