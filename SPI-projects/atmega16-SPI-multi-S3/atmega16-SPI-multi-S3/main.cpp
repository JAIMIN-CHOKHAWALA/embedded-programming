/*
 * THIS IS S3 atmega16-SPI-multi-S3.cpp
 *
 * Created: 23-10-2021 15:34:33
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

#define MOSI 5
#define MISO 6
#define SCK 7

void pattern_1 () {
	DDRC  =0xFF;
	PORTC = MASK(0);
	
	short int i = 0;
	while (i <= 7) {
		PORTC |= MASK(i);
		++i;
		_delay_ms(500);
	}
	i = 0;
}

int main(void) {
	DDRC = 0xFF; // output
	DDRB = (1 << MISO); // set MISO as output others as input
	SPCR = (1 << SPE); // Enable SPI pin and MSTR -> 0 slave mode
	
	while (1) {
		while ((SPSR & (1 << SPIF)) == 0);
		PORTC = SPDR; 
		
// 		if (SPDR == 1) {
// 			pattern_1();
// 		}
		
    }
}

