/*
 * input_capture_avr.cpp
 *
 * Created: 20-12-2021 14:13:40
 * Author : JAIMIN
 * About: 
    Input capture is used to find FREQUENCY OF DIGITAL PULSES, note you can
    detect rising edge and falling edge 
    then you can simply substract them 
    and multiply them with 1024 to find your frequency
 */ 
unsigned int capture = 0;

void setup () {
    // pinMode(49, OUTPUT);
    // digitalWrite(49, HIGH);

    // Enable global interrupt
    sei(); 
    
    // Enable required timer1 interrupt
    TIMSK4 |= (1 << ICIE4); 
    
    // config your timer (normal mode) ~65000; 
    TCCR4A =
    
    // config clock select (1024 bits)
    TCCR4A |= (1 << CS40); 
        
    // TIMER starts from 
    TCNT4 = 0;
    
    // ICES1 bit 0 for falling edge detection & 1 for rising edge detection
    TCCR4B |= (1 << ICES4);  
    
    Serial.begin(9600);
}

void loop () {
    
}

ISR (TIMER4_CAPT_vect) {
    capture = ICR4;
    Serial.print(capture);
    Serial.print("\n");
}
