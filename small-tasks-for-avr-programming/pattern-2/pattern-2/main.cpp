/*
 * pattern-2.cpp
 *
 * Created: 04-10-2021 15:10:11
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include<util/delay.h>

int main(void) {
	
	// setup
	DDRA = 0x00;
	DDRB = 0xFF;
	PORTB = 0x00;
	unsigned int state = 0x01;
	
	while (1) { // 0000 0000
		if (PINA) {
			state=1;
		} else {
			if(state==1){
				PORTB^=1;
				state=0;
			}
		}
		
	}
	
}

