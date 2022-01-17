/*
 * timer.cpp
 *
 * Created: 08-10-2021 15:53:15
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#define LED PD4

int main(void) {
	// setup
	uint8_t timeOverFlowCount = 0;
	DDRD = 0xFF;
	TCNT0 = 0x00; // timer/counter 
	TCCR0A = (1 << CS00) | (1 << CS02);
	
    while (1) {
		while ((TIFR0 & 0x01) == 0) {
			TCNT0 = 0x00;
			TIFR0 = 0x01; // clear timer0 overflow
			timeOverFlowCount++;
			if (timeOverFlowCount >= 6) {
				PORTD ^= (0x01 << LED);
				timeOverFlowCount = 0;
			}
		}
    }
}

