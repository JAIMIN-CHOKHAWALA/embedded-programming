/*
 * spi-device-to-device-master.cpp
 *
 * Created: 16-11-2021 14:55:12
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>

void i2c_write (unsigned char data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void i2c_start (void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void i2c_init () {
	TWSR = 0x00;
	TWBR = 0x47;
	TWCR = 0x04; // 0000 0100	
}

void i2c_stop () {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void i2c_listen () {
	while (!(TWCR & (1 << TWINT)));
}

/*
unsigned char i2c_read (unsigned char rec) {
	if (rec == 0) {
		TWCR = (1 <<  TWINT) | (1 << TWEN) | (1 << TWEA);
	} else {
		TWCR = (1 << TWINT) | (1 << TWEN);
	}
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}
*/

unsigned char i2c_read () {
	TWCR = (1 <<  TWINT) | (1 << TWEN) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

int main(void) {
	// setup
	unsigned char i;
	DDRA = 0xFF; // testing
	i2c_init();
	i2c_start();
	i2c_write(0x41);
		
	while (1) {
		PORTA = i2c_read();
		
		/*
		i2c_write(0xFF);
		_delay_ms(1000);
		i2c_write(0x55);
		_delay_ms(1000);
		*/
	}
}

