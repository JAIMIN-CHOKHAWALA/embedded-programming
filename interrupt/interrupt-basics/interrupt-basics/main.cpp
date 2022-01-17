#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
	DDRB |= 0x20; // 0010 0000
	TCNT0 = -32;
	TCCR0 = 0x01; // normal mode, no pre-scaller
	
	TIMSK = (1 << TOIE0); // enable timer0 overflow interrupt
	sei(); // enable interrupts;
	
	DDRC = 0x00;
	DDRD = 0xFF;

    while (1) {
		PORTD = PINC;
    }
}

ISR (TIMER0_OVF_vect) {
	TCNT0 = -32;
	PORTB ^= 0x20; // 0010 0000
}