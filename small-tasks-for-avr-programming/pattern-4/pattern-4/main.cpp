/*
 * pattern-4.cpp
 *
 * Created: 04-10-2021 14:56:06
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x01;
    while (1) {
		_delay_ms(1000);
		PORTA <<= 2;
		if (PORTA == 0x80) {
			PORTA = 0x01;
		}	
    }
}

