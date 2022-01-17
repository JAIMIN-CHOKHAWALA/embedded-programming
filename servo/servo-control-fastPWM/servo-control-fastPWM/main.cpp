/*
 * servo-control-fastPWM.cpp
 *
 * Created: 19-11-2021 15:40:06
 * Author : JAIMIN
 
 We are using Fast PWM with ICR1 mode
 => 14th mode in table
 => timer1 => (A, B)
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = 0xFF;
	TCCR1A = (1 << WGM11) | (1 << COM1A1) | (1 << COM1A0); // INVERTED
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10);
	ICR1 = 19999; // compare at 20000 (after 20000 cnts);
	
	// OCR1A = ICR1 - 2000; // 18000 => THIS IS SETTING INITIAL POSITION TO 0 deg
	
	/*
	18000 + 1200 = 19200 = ANTI CLOCK (180)
	18000 = 0
	18000 - 1200 = 17800 = CLOCK (180)
	*/
	
	//  1400 = 80 | 1500 = 90 | 1600 = 120
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

