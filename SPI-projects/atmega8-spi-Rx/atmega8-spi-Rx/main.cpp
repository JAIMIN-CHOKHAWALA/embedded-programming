/*
 * atmega8-spi-Rx.cpp
 *
 * Created: 22-10-2021 17:17:32
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define SS 2
#define MOSI 3
#define MISO 4
#define SCK 5

int main(void) {
	short int i = 8;
	DDRC = DDRD = 0xFF; 
	DDRB = (1 << MISO); // set MISO as output others as input
	SPCR = (1 << SPE); // Enable SPI pin and MSTR -> 0 slave mode
	
    while (1) {
		// PORTC = SPDR = 0x02; // sending 0000 0010
		PORTC = SPDR = i;
		while ((SPSR & (1 << SPIF)) == 0);
		PORTD = SPDR; // light PORTD according to received data
		_delay_ms(1000);
		--i;
		if (i < 0) i = 8;		
    }
}

