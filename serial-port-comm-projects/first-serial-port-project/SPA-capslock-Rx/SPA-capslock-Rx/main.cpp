/*
 * SPA-capslock-Rx.cpp
 *
 * Created: 20-10-2021 15:50:12
 * Author : JAIMIN
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))
#include <stdio.h>

void __init__ () {
	UCSR0B = (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0L = 0x33;
}

void all () {
	DDRB = 0xFF;
	PORTB = 0xFF;
}

void onFollowedByOff () {
	DDRB = 0xFF;
	PORTB = 0x55;
}


int main(void) {
	__init__();
	DDRD = 0xFF;	
		
	while (1) {
		while (!(UCSR0A & (1 << RXC0)));
		PORTD = UDR0;		
		printf("DONE");
	}
	
	return 0;
}