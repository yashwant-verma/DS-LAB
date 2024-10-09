// Given an array of integers, rotate the array of elements by k elements (left)

#include <stdio.h>
#include <stdio.h>

int main() {
    int n, k;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of elements to rotate: ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[i + k];
    }

    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }

    printf("Array after rotating left by %d elements: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
