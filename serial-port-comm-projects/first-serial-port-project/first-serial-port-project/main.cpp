/*
 * first-serial-port-project.cpp
 *
 * Created: 19-10-2021 13:23:38
 * Author : JAIMIN
 */

/* PROGRAM ON TRANSMITTER SIDE */
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define MASK(k) ((unsigned char)(1 << k))

int main(void) {
	DDRD |= MASK(1); // pin1 of portD as OUTPUT (transmitter)
	DDRD &= ~MASK(0); // pin0 of portD as INPUT (receiver)
	
	PORTD |= MASK(0); // pin0 of portD is at TRUE
	
	int	UBBRValue = 25; // 25 baud rate ~ 25bits/second
	
	UBRRH = (unsigned char)(UBBRValue >> 8);
	
	UBRRL = (unsigned char)(UBBRValue);
	
	// NOW, enable receiver and transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN);
	
	// set 2 stop bits & data bits length is 8 bits
	UCSRC = (1 << USBS) | (3 << UCSZ0);
	
	while (1) {
		if (PINC == 0x00) {
			while (!(UCSRA & (1 << UDRE)));
			UDR = 0xF0; // //once transmitter is ready sent eight bit data
			_delay_ms(250); // get data our of here
		}
		
    }
}

