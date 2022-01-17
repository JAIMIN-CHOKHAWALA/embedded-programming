/*
 * spi-testing-s1.cpp
 *
 * Created: 25-10-2021 17:01:52
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

#define MOSI 5
#define MISO 6
#define SCK 7

void pattern () {
	short int i = 0;
	PORTC = MASK(0);
	
	while (i <= 7) {
		PORTC |= MASK(i);	
		_delay_ms(500);
		++i;
	}
	i = 0;
}

int main(void) {
	DDRC = 0xFF;
	DDRB = (1 << MISO); // set MISO as output others as input
	SPCR = (1 << SPE); // Enable SPI pin and MSTR -> 0 slave mode
	
    while (1) {
		while (!(SPSR & (1 << SPIF)));
		if (SPDR == 'A') {
			pattern();
		}
    }
}

