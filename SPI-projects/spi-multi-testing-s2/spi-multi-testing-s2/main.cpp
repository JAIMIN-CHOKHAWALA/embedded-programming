/*
 * spi-multi-testing-s2.cpp
 *
 * Created: 25-10-2021 17:26:36
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

#define MISO 6

int main(void) {
    while (1) {
		 DDRC = 0xFF;
		 DDRB = (1 << MISO); // set MISO as output others as input
		 SPCR = (1 << SPE); // Enable SPI pin and MSTR -> 0 slave mode
		 short int i = 0;

		 
		 while (1) {
			 if (PORTC == 0x55 || PORTC == 0xAA) {
				 i = 0;
				 PORTC = 0;
			 }
			 
			 // receiving 
			 while (!(SPSR & (1 << SPIF)));
			 i = SPDR;
			 PORTC |= MASK(i);
			 
// 			 // sending
// 			 SPDR = ++i;
// 			 while (!(SPSR & (1 << SPIF)));
		 }		
    }
}

