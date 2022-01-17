#include<stdio.h>
#include<stdlib.h>

// Syntax: itoa(int, outputVar, base)
int main(int argc, char const *argv[]) {
    int a = 100;
    char bin[8];
    char oct[10];
    char hex[10];
    
    // convert and save
    itoa(a, bin, 2);
    itoa(a, oct, 8);
    itoa(a, hex, 16);
    
    printf("Decimal: %d & Bin: %s\n", a, bin);
    printf("Decimal: %d & Oct: %s\n", a, oct);
    printf("Decimal: %d & Hex: %s\n", a, hex);

    return 0;
}