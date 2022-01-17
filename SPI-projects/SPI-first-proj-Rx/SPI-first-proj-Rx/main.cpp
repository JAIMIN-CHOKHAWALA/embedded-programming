/*
 * SPI-first-proj.cpp
 *
 * Created: 22-10-2021 16:41:10
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#define MASK(k) ((unsigned char)(1 << k))

#define MISO 3


int main(void) {
	DDRB = (1 << MISO);
	SPCR = (1 << SPE); // enable SPI slave
	DDRA = 0xFF;
	
	while (1) {
		while (!(SPSR & (1 << SPIF))); // wait for finish transfer
		PORTA = SPDR;
    }
	
	return 0;
}

 