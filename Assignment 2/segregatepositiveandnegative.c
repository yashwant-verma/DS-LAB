/*
Question 3---
Write a C program to segregate positive and negative numbers in the same array.
The program should rearrange the array so that all negative numbers appear before
all positive numbers while maintaining their relative order.
*/

#include <stdio.h>

int main() {
    
    int arr[50] ,temp[50];
    int i,size,negIndex = 0;
    printf("ENter the size of an array \n");
    scanf("%d",&size);
    
    printf("Enter the Array elements\n");
    for (i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }


    for (i = 0; i < size; i++) {
        if (arr[i] < 0) {
            temp[negIndex++] = arr[i];
        }
    }
   
    for (i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            temp[negIndex++] = arr[i];
        }
    }

    for (i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    printf("Rearranged array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
