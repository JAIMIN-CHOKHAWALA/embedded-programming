/*
 * delay1sec-1.cpp
 *
 * Created: 11-10-2021 14:19:20
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#define MASK(k) ((unsigned int)(1 << k))

int main(void) {
	// setup
	DDRA |= MASK(0);
	
	TCCR1A |= 1 << CS12;
	TCNT1 = 49910;
	
	TIMSK1 |= (1 << TOIE1);
	sei();
		
	while (1) {
	}	
}

ISR (TIMER1_OVF_vect) {
	PORTA ^= MASK(0); 
	TCNT1 = 49910;

}

