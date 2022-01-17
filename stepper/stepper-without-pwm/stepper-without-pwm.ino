#include <avr/io.h>
#include <util/delay.h>
#define MASK(k) ((unsigned char)(1 << k))
// 1 => 23 (violet), 2 => 22 (blue) | 3 => 24(orange), 4 => 25(unknown)

void testing () {
   digitalWrite(22, HIGH);
    _delay_us(1500);
    digitalWrite(22, LOW);
    
    digitalWrite(23, HIGH);
    _delay_us(1500);
    digitalWrite(23, LOW);
    
    digitalWrite(24, HIGH);
    _delay_us(1500);
    digitalWrite(24, LOW);
    
    digitalWrite(25, HIGH);
    _delay_us(1500);   
    digitalWrite(25, LOW); 
}

int main () {
  DDRA = MASK(0) | MASK(1) | MASK(2) | MASK(3);
    
  while (1) {
    analogWrite(22, 50);
    _delay_us(1500);
    analogWrite(22, 0);

    analogWrite(23, 70);
    _delay_us(1500);
    analogWrite(23, 0);

    analogWrite(24, 90);
    _delay_us(1500);
    analogWrite(24, 0);

    analogWrite(25, 110);
    _delay_us(1500);
    analogWrite(25, 0);   
  }
}
