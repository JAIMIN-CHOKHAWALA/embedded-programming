


#include <avr/io.h>
#include <util/delay.h>
unsigned char state_A = 0, state_B = 0, prev_state_A = 0, prev_state_B = 0;
int i = 0;
int main(void) {
	DDRA = 0x00;
	PORTA = 0x03;
	DDRB = 0xFF;
	/*Serial.begin(9600);*/
	while (1) {
		/*Serial.println(i);*/
		PORTB = i;
		state_A = ((~PINA) & 0x01); //Output A
		state_B = ((~PINA) & 0x02); //Output B
		if (state_A != prev_state_A) {
			/*prev_state_A = state_A;*/
			if (state_B != state_A) { // cw
				i++;
			} else { // acw
				i--;
			}
		} else {
			if (state_B != prev_state_B) {
				/*prev_state_B = state_B;*/
				if (state_A != state_B) {
					i--;
				}
				else {
					i++;
				}
			}
		}
		Serial.println(i);
	}
}
