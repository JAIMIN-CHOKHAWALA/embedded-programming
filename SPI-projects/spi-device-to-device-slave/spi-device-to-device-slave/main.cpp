/*
 * spi-device-to-device-slave.cpp
 *
 * Created: 16-11-2021 14:55:45
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>

void i2c_init_slave (unsigned char sl_addr) {
	TWCR = 0x04; // just  enable it
	TWAR = sl_addr; // addr of slave
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);	
}

void i2c_write (unsigned char data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void i2c_listen () {
	while (!(TWCR & (1 << TWINT)));	
}

unsigned char i2c_read (unsigned char rec) {
	if (rec == 0) {
		TWCR = (1 <<  TWINT) | (1 << TWEN) | (1 << TWEA);
		} else {
		TWCR = (1 << TWINT) | (1 << TWEN);
	}
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

void i2c_stop () {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}


int main(void) {
	unsigned char i;
	DDRA = 0xFF;
	// i2c_listen();
		
	while (1) {
		i2c_init_slave(0x40); // 0000 0011
	
		i2c_write('A');
		_delay_ms(2000);
		i2c_write('B');
		_delay_ms(2000);
		// i = i2c_read(0);
		// PORTA = i;	
	}
}