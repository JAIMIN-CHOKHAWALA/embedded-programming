#include <avr/io.h>
#include <util/delay.h>

void configADC () {
	ADCSRA = (1 << ADEN) | (1 << ADPS2); // 16 bit
	ADMUX = 0x03; // 0000 0011 A3 pin
}

int main(void) {
	Serial.begin(9600);
	int adc = 0;
	configADC();
	
    while (1) {
		ADCSRA |= (1 << ADSC);
		while (ADCSRA & (1 << ADCS));
		adc = ADCW;
		Serial.println(adc);
		_delay_ms(300);
		
    }
}

