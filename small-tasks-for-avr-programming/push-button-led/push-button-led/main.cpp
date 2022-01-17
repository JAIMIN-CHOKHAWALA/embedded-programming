/*
 * push-button-led.cpp
 *
 * Created: 05-10-2021 10:25:08
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void) {
	// setup
	DDRB = 0x01;
	DDRA = 0x00;
	unsigned char btn;
	PORTB = 0x01;
	
    while (1) {
		btn = PINA & (1 << PA0) == 1;
		if (btn) { // if PINA0 pressed
			if (btn != PINA & (1 << PA0) == 1) {
				PORTB = PORTB;
			} else {
				PORTB = !PORTB;	
			}
		
			// _delay_ms(3000);
					
		}
    }
}

