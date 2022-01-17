#include <NewPing.h>

#define TRIG_PIN 10
#define ECHO_PIN 11
#define MAX_DIS 400

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIS);

void setup() {
    Serial.begin(9600);
    delay(50);
}

void loop() {
    Serial.println("Distance (cm): ");
    Serial.println(sonar.ping_cm());
    delay(500);
}
