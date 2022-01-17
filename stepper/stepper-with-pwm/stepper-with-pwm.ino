#include <avr/io.h>
#include <util/delay.h>

const int rotate (int angle) {
  double x = (double)angle * 3500;
  double y = x/(double)180;
  return 1000+y;
}

int main(void) {
  DDRB = 0xFF;
  TCCR1A = (1 << WGM11) | (1 << COM1A1) | (1 << COM1A0); // INVERTED
  TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11); // 8 bit prescaller
  ICR1 = 39999; // compare at 40000 (after 40000 cnts);
  
  while (1) {
   OCR1A = rotate(0);
    _delay_ms(3000);
    OCR1A = rotate(45);
    _delay_ms(3000);
    OCR1A = rotate(90);
    _delay_ms(3000);
    OCR1A = rotate(135);
    _delay_ms(3000);
     OCR1A = rotate(180);
    _delay_ms(3000);
  }
}
