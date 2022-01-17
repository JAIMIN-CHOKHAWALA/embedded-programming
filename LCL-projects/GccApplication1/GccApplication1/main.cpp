/*
 * GccApplication1.cpp
 *
 * Created: 17-11-2021 14:50:25
 * Author : JAIMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU

# define F_CPU 16000000UL // clock speed is 16MHz

#endif





#define LCD_DATA PORTB          // port B is selected as LCD data port

#define ctrl PORTA              //  port D is selected as LCD command port

#define en PA2                  // enable signal is connected to port D pin 7

#define rw PA1                 // read/write signal is connected to port D pin 6

#define rs PA0                  // register select signal is connected to port D pin 5





//**************sending command on LCD***************//


void LCD_cmd(unsigned char cmd)

{

  LCD_DATA = cmd;      // data lines are set to send command*

  PORTA  &= ~(1<<rs);  // RS sets 0

  PORTA  &= ~(1<<rw);  // RW sets 0

  PORTA  |= (1<<en);   // make enable from high to low

  _delay_ms(10);

  PORTA  &= ~(1<<en);

  

  return;

}



//*****************write data on LCD*****************//

void LCD_write(unsigned char data)

{

  LCD_DATA= data;       // data lines are set to send command

  PORTA  |= (1<<rs);    // RS sets 1

  PORTA  &= ~(1<<rw);   // RW sets 0

  PORTA  |= (1<<en);    // make enable from high to low

  _delay_ms(10);

  PORTA &= ~(1<<en);

  

  return ;

}

void init_LCD(void)

{

  LCD_cmd(0x38);           // initialization in 8bit mode of 16X2 LCD

  _delay_ms(1);

  LCD_cmd(0x01);          // make clear LCD

  _delay_ms(1);

  LCD_cmd(0x02);          // return home

  _delay_ms(1);

  LCD_cmd(0x06);          // make increment in cursor

  _delay_ms(1);

  LCD_cmd(0x80);          // ?8? go to first line and ?0? is for 0th position

  _delay_ms(1);

  

  return;

}
//*****************write STRING on LCD*****************//

void LCD_Write_String(char *a)
{
  int i;
  for(i=0;a[i]!='\0';i++)
  {
    char big = a[i];
    LCD_write(big);
  }
  
}

#define LCD_DATA PORTB
#define CTRL PORTA
#define RS PA0
#define RW PA1
#define EN PA2

int main(void) {
    
  while (1) {
    DDRB = 0xFF; // PORT B data output
    DDRA = 0x07; // 0000 0111 => 0x07
  
    // init_LCD(); // init LCD
    _delay_ms(10);
  
    LCD_cmd(0x0C); // display on cursor off
    _delay_ms(10);
  
    LCD_Write_String("jaimin__chokhawala");
    _delay_ms(100);
    //LCD_cmd(0x18);
    //LCD_cmd(0x18);
    LCD_cmd(0x0);
    LCD_write('|');
  
    LCD_cmd(0xC0); // move cursor to start of second line
    _delay_ms(100);
    LCD_cmd(0x1C);
    LCD_cmd(0x1C);
  
  
    LCD_Write_String(" Hello, World!-");
    _delay_ms(100);
  
    LCD_cmd(0x01); // clear screen
    _delay_ms(10);
  }
  
  
}

