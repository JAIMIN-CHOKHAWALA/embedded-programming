#include <avr/io.h>
#include <util/delay.h>
#define TRIG_PIN 10 // 4
#define ECHO_PIN 11 // 5
#define MASK(k) ((unsigned char)(1 << k))

long dur;
double dis;
long disInt;

const int convertInt (double dis) {
    if (dis - (int)dis >= 0.5) {
        return (int)dis + 1;
    } else if (dis - (int)dis < 0.5) {
        return (int)dis;
    }       
}

int main () {
    // trig pin output & echo pin input
    DDRB = MASK(4);
    Serial.begin(9600);

    while (1) {
        PORTB &= ~MASK(4);  
        _delay_us(2);

        PORTB |= MASK(4);
        _delay_us(10);
        PORTB &= ~MASK(4);

        dur = pulseIn(ECHO_PIN, HIGH);
        dis = dur * 0.017;
        disInt = convertInt(dis);

        Serial.print("distance(cm): ");
        Serial.print(disInt); 
        Serial.print("\n");
        _delay_ms(100);    
    }
    return 0;
}
