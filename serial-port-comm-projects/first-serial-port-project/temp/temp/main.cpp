?#include <avr/io.h>
#define F_CPU 1000000UL
#define <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

/* Receiver side code */
int main (void)  {
	DDRC = 0xFF; // portC full output
	DDRD &= ~MASK(0); // set pin0 as input - Rx
	DDRD |= MASK(1); // set pin1 as output - Tx
	
	int UBRR_Value = 25; // 2400 baud rate ~ 2400 bits/second
	UBRRH = (unsigned char) (UBRR_Value >> 8);
	UBRRL = (unsigned char) (UBRR_Value);
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << USBS) | (3 << UCSZ0);
	
	unsigned char receiveData;
	
	while (1) {
		while (!(UCSRA & (1 << RXC)));
		receiveData = UDR;
		if (receiveData == 0xF0) {
			PORTC ^= MASK(0);
			_delay_ms(250);
		}
	}
}