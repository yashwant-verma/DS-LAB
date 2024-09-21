/*
Write a C program to find the sum of both the primary and secondary diagonals of a square
matrix. The program should:
● Take the matrix dimensions and the matrix itself as input from the user.
● Compute the sum of the primary diagonal (from top-left to bottom-right) and the
secondary diagonal (from top-right to bottom-left).
● Display both diagonal sums.
*/


#include <stdio.h>

int main() {
    int arr[20][20], r, diagonal_sum=0,anti_diagonal_sum=0;

    printf("Enter the size of the square matrix (up to 20):\n");
    scanf("%d", &r);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        diagonal_sum += arr[i][i];            
        anti_diagonal_sum += arr[i][r - 1 - i]; 
    }

    printf("Sum of diagonal elements is: %d\n", diagonal_sum);
    printf("Sum of anti-diagonal elements is: %d\n", anti_diagonal_sum);

    return 0;
}
