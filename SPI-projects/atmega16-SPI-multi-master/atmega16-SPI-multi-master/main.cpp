/*
 * THIS IS MASTER atmega16-SPI-multi-master.cpp
 *
 * Created: 23-10-2021 15:33:34
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

// pins
#define MOSI 5
#define MISO 6
#define SCK 7

// SS pins 0 1 2
#define SS_1 0
#define SS_2 1
#define SS_3 2	

int main(void) {
	// switch	
	DDRB = (1 << MOSI) | (1 << SCK) | (1 << SS_1) | (1 << SS_2) | (1 << SS_3); // SS_1 for channel-1 communication
	DDRC = 0xFF; // testing port
	
	// 0000 0111 => 07
	PORTB |= 0x07; // all SS_1/2/3 are HIGH and working	
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // SPE = spi enable->1 | MSTR = select master->1 | data rate (SPRO) = fosc / 16
		
    while (1) {
		// SPDR = 0x01; // 0000 0001
		while (!(SPSR & (1 << SPIF)));
		PORTC = SPDR;
		
    }
}