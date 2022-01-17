/*
 * GccApplication2.cpp
 *
 * Created: 04-10-2021 14:13:50
 * Author : JAIMIN
 */

#include <avr/io.h>

int main(void) {
    /* Replace with your application code */
	DDRA = 0x0;
	DDRB = 0xFF;
    while (1) {
		PORTB = PINA;
    }
}

