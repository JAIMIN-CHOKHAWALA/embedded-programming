/*
 * I2C-first.cpp
 *
 * Created: 26-10-2021 16:28:07
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#define MASK(k) ((unsigned char)(1 << k))

/* STEP-1 Initialize I2c */
void i2c_init () {
	TWBR = 0x62; // 98 baud rate, using calculations
	TWCR = (1 << TWEN); // enable I2C
	TWSR = 0x00; // No pre-scalling	
}

/* I2C start condition */
void i2c_start () {
	TWCR = (1 << TWINT) | (1 << TWEN)| (1 << TWSTA); // set TWEN '1' to start I2C comm (start condition for I2C)
	while (!(TWCR & (1 << TWINT))); // stop condition (check for start condition success)
}

/* I2C stop condition / I2C after writing ends */
void i2c_write (char x) {
	TWDR = x; // data register
	TWCR = (1 << TWINT) | (1 << TWEN);  // enable I2C & clear interrupt
	while (!(TWCR & (1 << TWINT)));	
}

char i2c_read () {
	TWCR = (1 << TWEN) | (1 << TWINT); // // enable I2C & clear interrupt
	while (!(TWCR & (1 << TWEN))); // read successful 
	return TWDR;
}


int main(void) {
	unsigned char slave = 0x40; // 0100 0000
	DDRA = 0xFF; // A - test output
	i2c_init();
	i2c_start();
	i2c_write(slave); // write to slave address
	
    while (1) {
		i2c_write(0x55);
		_delay_ms(500);
		i2c_write(0xAA);
		_delay_ms(500);
    }
}

