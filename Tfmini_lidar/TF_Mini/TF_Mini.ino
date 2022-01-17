#include <TFMini.h>
#include <SoftwareSerial.h>

SoftwareSerial tfserial(19, 18);
TFMini tfmini;
uint16_t dist, strength;

void setup() {
  Serial.begin(9600); // init hardware serial port
  while (!Serial); // wait for serial port to connect
  Serial.println("Initializing...");

  tfserial.begin(TFMINI_BAUDRATE); // init data rate for software serial port

  tfmini.begin(&tfserial); // init TF mini sensor
}

void loop() {
  Serial.println("Program began");
  dist = tfmini.getDistance();
  strength = tfmini.getRecentSignalStrength();
  
  //display
  Serial.print("Bytes sent: ");
  Serial.print(
  Serial.print("Distance(cm): ");
  Serial.print(dist);
  Serial.print("\nSignal strength: ");
  Serial.print(strength);
  Serial.print("\n");

  delay(25);
}
