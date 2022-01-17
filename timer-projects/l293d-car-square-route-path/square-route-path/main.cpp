#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))


int main(void) {
	/*
	DDRB = 0xFF;
	DDRE = 0xFF;
	
	TCCR3A = 0xA2; // 1010 0010
	TCCR3B = 0x09; // 0000 1001
	TCCR2A = 0xA2; // 1010 0010
	
    while (1) {
		OCR2A = 255;
		OCR3A = 255;
		_delay_ms(4000);
		
		OCR1A = 255;
		OCR3A = 0;
		OCR3B = 255;
		_delay_ms(1000);
    }
	*/
	DDRB = 0x00;
	DDRE = 0x00;

	while (1) {
		PORTB |= MASK(5);
		PORTE |= MASK(3);
		_delay_ms(4000);
		
		PORTB &= MASK(5);		
		_delay_ms(1000);
	}
	
}


