/*
 * timer-task-2.cpp
 *
 * Created: 15-10-2021 14:04:16
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

int main(void) {
	DDRB = 0xFF;
	
	TCCR0A = 0x83; // fast PWM 
	TCCR0B = 0x02; // 8 bit p-s
	unsigned char i = 0;
	
    while (1) {
		_delay_ms(1);
		OCR0A = i;
		++i;
		
    }
}

