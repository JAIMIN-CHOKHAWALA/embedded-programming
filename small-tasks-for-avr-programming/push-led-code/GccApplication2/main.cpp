/*
 * GccApplication2.cpp
 *
 * Created: 04-10-2021 11:49:16
 * Author : JAIMIN
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0xFF;
	DDRB = 0xFF;
    while (1) 
    {
		PORTB = PINA;
    }
	
	return 0;
}

