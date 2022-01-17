/*
 * servo-practical.cpp
 *
 * Created: 08-12-2021 14:44:06
 * Author : JAIMIN
 */

#include <avr/io.h>
#include <util/delay.h>

void timer_init () {
	DDRB = 0xFF;
	TCCR1A = (1 << WGM11) | (1 << COM1A1) | (1 << COM1A0); // INVERTED
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10);
	ICR1 = 19999;
}

int main(void) {
	timer_init();
	
    while (1) {
		OCR1A = ICR1 - 1500;
		_delay_ms(2000);
		
		/*
		OCR1A = ICR1 - 800; // 20000 - 800 = 19200
		_delay_ms(2000);
		OCR1A = ICR1 - 2200; // 20000 - 2200 = 17800
		_delay_ms(2000);
		*/
	}
	
}

