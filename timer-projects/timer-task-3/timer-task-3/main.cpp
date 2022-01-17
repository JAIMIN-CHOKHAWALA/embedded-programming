/*
 * timer-task-3.cpp
 *
 * Created: 15-10-2021 14:17:48
 * Author : JAIMIN
 */
#include <avr/io.h>
#include <util/delay.h>

int main () {
	
	DDRB = 0xFF;
	TCCR0A = 0x83;
	TCCR0B = 0x02;
	unsigned char i = 0;
	unsigned char j = 1;
	while (1) {
		_delay_ms(1);
		
		OCR0A = i;
		i += j;
		if (i == 255) {
			j =- 1;
		}
		if (i == 0) {
			i=1;
			j=1;
		}
	}
	
	return 0;
}
