/*
 * servo-basics.cpp
 *
 * Created: 19-11-2021 14:45:08
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define W 60000

int main(void) {
	DDRA = 0x01;
    while (1) {
		PORTA = 0x01; // rotate 0 deg
		_delay_us(1000);
		PORTA= 0x00;
		
		_delay_ms(2000);
		
		PORTA = 0x01; // rotate 90 deg
		_delay_us(1000); // it rotates 90 deg in 1500us => 90 deg / 1500us
		PORTA= 0x00;
		
		_delay_ms(2000);
		
		PORTA = 0x01; // rotate 180 deg
		_delay_us(1000);  
		PORTA = 0x00;
		
		_delay_ms(2000);
    }
}

