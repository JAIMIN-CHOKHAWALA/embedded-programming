/*
 * spi-multi-testing-mas.cpp
 *
 * Created: 25-10-2021 17:21:02
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

// config
#define MOSI 5
#define MISO 6
#define SCK 7

// pins 
#define SS_1 0
#define SS_2 1

void toggleSlaves () {
	PORTB ^= MASK(0);
	PORTB ^= MASK(1);
}

int main(void) {
	DDRB = (1 << MOSI) | (1 << SCK) | (1 << SS_1) | (1 << SS_2);
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	DDRC = 0xFF;
	PORTB &= ~MASK(0);
	PORTB |= MASK(1);
	short int i = 0;
	
    while (1) {
		_delay_ms(1000);
		if (i > 7) i = 0;
		//sending
		SPDR = i;
		while (!(SPSR & (1 << SPIF)));
		
		toggleSlaves();
		++i;
    }
}

