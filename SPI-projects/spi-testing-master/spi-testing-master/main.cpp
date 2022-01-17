/*
 * spi-testing-master.cpp
 *
 * Created: 25-10-2021 17:00:53
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#define MASK(k) ((unsigned char) (1 << k))

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

int main(void) {
	DDRB = (1 << MOSI) | (1 << SCK) | (1 << SS);
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);	
	
    while (1) {
		SPDR = 'A';
		while (!(SPSR & (1 << SPIF)));
    }
}

