//Find the number that appears once, and the other numbers twice.


#include <stdio.h>

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[100]; 
    int count[100] = {0};

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    printf("The numbers that appear once: ");
    for (int i = 0; i < 100; i++) {
        if (count[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("The numbers that appear twice: ");
    for (int i = 0; i < 100; i++) {
        if (count[i] == 2) {
            printf("%d ", i);
        }
    }

    return 0;
}


