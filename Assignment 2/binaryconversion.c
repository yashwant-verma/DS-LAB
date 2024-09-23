/*Write a C program that takes a decimal number as input and prints its binary
representation in the correct order.*/


#include <stdio.h>

int main() {
    int decimal, bin[32], i = 0;
   
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }

    while (decimal > 0) {
        bin[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    return 0;
}
