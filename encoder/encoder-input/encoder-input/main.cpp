/*
 * encoder-input.cpp
 *
 * Created: 20-11-2021 14:21:40
 * Author : JAIMIN
 */ 

/*
A == B => ACW
A != B => CW
*/

#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))

unsigned char curr_a, curr_b;
unsigned char prev_a = 0, prev_b;
int i = 0;
int status = 0;

int main(void) {
	DDRB = 0xFF;
	PORTA = MASK(0) | MASK(1); // pull up
	/*PORTB = i;*/
	
	while (1) {
		curr_a = ~PINA & MASK(0);
		curr_b = ~PINA & MASK(1);
		status = i;
		
		if (curr_a != prev_a) {
			prev_a = curr_a;
			if (curr_b != curr_a) {
				++i;
			} else {
				--i;
			}
		} else {
			if (curr_b != prev_b) {
				prev_b = curr_b;
				if (curr_a != curr_b) {
					--i;
				} else {
					++i;
				}
			}
		}
		if (i > status) {
			PORTB = 0x01;
		} else {
			PORTB = 0x02;
		}
	}
}

// 		currentState = (PINA & MASK(0));
// 		if ((currentState != lastState) && currentState == 1) {
// 			currentStateB = PINA & MASK(1);
// 			if (currentStateB == currentState) {
// 				// ACW
// 				PORTD = MASK(1);
// 			} else if (currentStateB != currentState){
// 				// cw
// 				PORTD = MASK(0);
// 			}
// 		}
// 		lastState = currentState;