//#include <SoftwareSerial.h>
//SoftwareSerial Serial2(10, 11);
uint16_t dist, strength, check;
int uart[9];
int i;
const int HEADER = 0x59;

void printArray (int arr[]) {
    Serial.print("Array items: ");
    for (int j = 0; j < 9; ++j) {
        Serial.print(arr[j]);
        Serial.print(" ");
    }
    Serial.print("\n");
}

void setup () {
    Serial.begin(115200);
    Serial2.begin(115200); 
}


void loop () {
    if (Serial2.available()) {
        if (Serial2.read() == HEADER) {
            uart[0] = HEADER;
            if (Serial2.read() == HEADER) {
                uart[1] = HEADER;
                for (i = 2; i < 9; ++i) {
                    uart[i] = Serial2.read();
                }

                // printArray(uart);
                check = 0;
                for (i = 0; i < 8; ++i) {
                    check += uart[i];
                }
                
                if ((check & 0xFF) == uart[8]) {
                    dist = uart[2] + (uart[3] * 256);
                    strength = uart[4] + (uart[5] * 256);
                    Serial.print("distance(cm): ");
                    Serial.print(dist);
                    Serial.print("\tstrength: ");
                    Serial.print(strength);
                    Serial.print("\n");
                    delay(100);
                }
                
            }
        }
    }
    Serial.println("program began");
}
