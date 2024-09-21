/*
Write a C program that checks whether a given square matrix is symmetric. A matrix is
symmetric if it equals its transpose. The program should:
● Take a square matrix as input.
● Check and display whether the matrix is symmetric.
*/
#include <stdio.h>

int main() {
    int arr[50][50], trans[50][50];
    int r, c, i, j;

    printf("Enter the number of rows:\n");
    scanf("%d", &r);
    printf("Enter the number of columns:\n");
    scanf("%d", &c);

    if (r != c) {
        printf("Matrix is not symmetric because it is not square");
        return 1; 
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            trans[j][i] = arr[i][j];
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (arr[i][j] != trans[i][j]) {
                printf("Matrix is not symmetric");
                return 0; 
            }
        }
    }

    printf("Matrix is symmetric");
    return 0;
}
