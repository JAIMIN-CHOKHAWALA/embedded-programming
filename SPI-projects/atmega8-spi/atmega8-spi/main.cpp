/*
 * atmega8-spi.cpp
 *
 * Created: 22-10-2021 17:16:45
 * Author : JAIMIN
 */ 

/* MASTER PROGRAMMING */ 

#include <avr/io.h>
#include <util/delay.h>

/* defining SPI pins */
#define SS 2
#define MOSI 3
#define MISO 4
#define SCK 5

int main(void) { 
	short int i = 0;
	DDRD = 0xFF;
	DDRC = DDRD;
	
	DDRB = (1 << MOSI) | (1 << SS) | (1 << SCK); // set in/out of B where MISO is only input pin
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // SPE = spi enable->1 | MSTR = select master->1 | data rate (SPRO) = fosc / 16
	
	
    while (1) {
		SPDR = i++;
		PORTC = SPDR;// sending 0000 0001 using SPDR
		while (!(SPSR & (1 << SPIF)));
		PORTD = SPDR; // Receiving data on PORTD
		_delay_ms(1000);
		if (i > 8) i = 0;
    }
}

