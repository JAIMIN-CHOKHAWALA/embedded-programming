/*
 * GccApplication1.cpp
 *
 * Created: 04-10-2021 13:45:24
 * Author : JAIMIN
 FF = 1111 1111 => ALL OUT
 */

#include <avr/io.h>


int main(void) {
    /* Replace with your application code */
	DDRA = 0xFE; // FIRST PIN IN
	
    while (1) {
		if (PINA == 0x01) {
			PORTA = 0xFF;
		} else {
			PORTA = 0x00;
		}
    }
}

