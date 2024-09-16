/*Write a C program to merge two sorted arrays of sizes m and n into a new sorted
array. Input the elements of both arrays in sorted order, merge them, and output the
merged array in sorted order.*/

//Solution

#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the size of the first array: ");
    scanf("%d", &m);
    int arr1[m];
    printf("Enter %d elements of the first array in sorted order: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n);
    int arr2[n];
    printf("Enter %d elements of the second array in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < m) {
        merged[k++] = arr1[i++];
    }
   
    while (j < n) {
        merged[k++] = arr2[j++];
    }

    printf("Merged sorted array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
