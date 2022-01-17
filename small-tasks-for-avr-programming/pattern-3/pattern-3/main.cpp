/*
 * pattern-3.cpp
 *
 * Created: 04-10-2021 14:31:37
 * Author : JAIMIN
 */

#include <avr/io.h>
#include <util/delay.h>


int main(void) {
    /* Replace with your application code */
	DDRA = 0xFF;
	PORTA = 0x01;
    while (1) {
		PORTA = PORTA << 1;
		_delay_ms(200);
		if (PORTA == 0x80) {
			PORTA = 0x01;
		}
    }
}

