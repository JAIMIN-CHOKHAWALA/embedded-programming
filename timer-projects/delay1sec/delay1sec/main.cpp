/*
 * delay1sec.cpp
 *
 * Created: 11-10-2021 14:00:52
 * Author : JAIMIN
 */ 

#include <avr/io.h>

void delay1sec () {
	TCNT1 = 15625;
	do {
		TCNT1 = (TCNT1 - 1);
	} while (TCNT1 > 0);
}

int main(void) {	
	DDRC = 0xFF;
	PORTC = 0x00;
	TCCR1B = (1 << CS10 | 1 << CS11);	
    while (1) {
		PORTC = 0xFF;
		delay1sec();
		delay1sec();
		PORTC = 0x00;
		delay1sec();
		delay1sec();
    }
	return 0;
}

