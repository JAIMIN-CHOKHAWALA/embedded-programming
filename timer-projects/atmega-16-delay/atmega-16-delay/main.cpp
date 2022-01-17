/*
 * atmega-16-delay.cpp
 *
 * Created: 11-10-2021 17:08:22
 * Author : JAIMIN
 */

#include <avr/io.h>

int main(void) {
	DDRB=0xFF;
	DDRC=0xFF;
	
    while(1) {
		for (int i=0;i<1000;i++) {
			PORTB = (1 << 1);
		}
		PORTC=~PORTC;
	}
}
