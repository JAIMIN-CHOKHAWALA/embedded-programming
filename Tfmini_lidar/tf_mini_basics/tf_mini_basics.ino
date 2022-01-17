#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
int dist, strength, check;
int uart[9];
int i;
const int HEADER = 0x59;

void setup () {
    Serial.begin(115200);
    mySerial.begin(115200);
}

long convertBitInt (int low, int high) {
    uint16_t data = 0;

    
}

void printArray (int arr[]) {
    Serial.print("Array items: ");
    for (int j = 0; j < 9; ++j) {
        Serial.print(arr[j]);
        Serial.print(" ");
    }
    Serial.print("\n");
}

void loop () {
    if (mySerial.available()) {
        if (mySerial.read() == HEADER) {
            uart[0] = HEADER;
            if (mySerial.read() == HEADER) {
                uart[1] = HEADER;
                for (i = 2; i < 9; ++i) {
                    uart[i] = mySerial.read();
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
                    delay(300);
                }
                
            }
        }
    }
}
