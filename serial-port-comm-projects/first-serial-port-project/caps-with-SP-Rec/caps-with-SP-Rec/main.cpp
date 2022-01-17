/*
 * caps-with-SP-Rec.cpp
 *
 * Created: 19-10-2021 17:16:36
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

int main(void) {
	DDRE |= MASK(0) | MASK(2); 
	
	// pull-up
	PORTE |= MASK(2);

	
		
	
	
    while (1) 
    {
    }
}

