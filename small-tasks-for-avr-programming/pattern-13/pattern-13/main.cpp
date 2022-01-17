/*
 * pattern-13.cpp
 *
 * Created: 06-10-2021 14:38:49
 * Author : JAIMIN
 */ 

#include <avr/io.h>

int main(void) {
	// setup
	DDRA = 0x55;
	PINA = 0xAA;
	
	while (1) {
		PORTA = (PINA << 1) | (PINA >> 7);
	}	
}


/*
// setup
DDRA = 0x55;
PORTA = 0xAA;
unsigned char i ;

while (1) {
	i=(~PINA);
	PORTA = (i << 1)|(i >> 7);
}
*/

