/*
 * timer-task-1.cpp
 *
 * Created: 15-10-2021 12:50:10
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

int main(void) {
	// generate PWM
	DDRB = 0xFF;
	TCCR0A = 0x83; // fast PWM 
	TCCR0B = 0x02; // 8 bit p-s
	OCR0A = 127;
	
	while (1) {
		_delay_ms(1);
		PORTB = ~PORTB;
	}
	
	return 0;
}

