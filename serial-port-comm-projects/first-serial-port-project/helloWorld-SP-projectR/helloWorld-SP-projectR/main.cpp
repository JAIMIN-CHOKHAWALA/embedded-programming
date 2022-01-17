 /*
 * helloWorld-SP-project.cpp
 *
 * Created: 19-10-2021 15:15:24
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
unsigned char ch = 'A';


int main(void) {
	UCSR0B = (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0L = 0x33;
	DDRC = 0xFF;
	
	while (1) {
		// !(UCSR0A & (1 << RXC0))
		while (UCSR0A == 0x00);
		PORTC = UDR0;
		_delay_ms(1000);
	}
	
	return 0;
}

