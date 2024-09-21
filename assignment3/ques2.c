/*
Write a C program to multiply two matrices. The program should:
● Ensure that the number of columns in the first matrix is equal to the number of rows in
the second matrix.
● Multiply the matrices and display the result.

*/
#include <stdio.h>

int main() {
    int arr1[20][20], arr2[20][20], mul[20][20];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter the number of rows of the first matrix:\n");
    scanf("%d", &r1);
    printf("Enter the number of columns of the first matrix:\n");
    scanf("%d", &c1);

    printf("Enter the number of rows of the second matrix:\n");
    scanf("%d", &r2);
    printf("Enter the number of columns of the second matrix:\n");
    scanf("%d", &c2);
    
    if (c1 == r2) {
        printf("Enter the elements of the first matrix:\n");
        for (i = 0; i < r1; i++) {
            for (k = 0; k < c1; k++) {
                scanf("%d", &arr1[i][k]);
            }
        }

        printf("Enter the elements of the second matrix:\n");
        for (k = 0; k < r2; k++) {
            for (j = 0; j < c2; j++) {
                scanf("%d", &arr2[k][j]);
            }
        }

        for (i = 0; i < r1; i++) {
            for (j = 0; j < c2; j++) {
                mul[i][j] = 0; 
                for (k = 0; k < c1; k++) {
                    mul[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        printf("The product of the matrices is:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c2; j++) {
                printf("%d ", mul[i][j]); 
            }
            printf("\n"); 
        }
    } else {
        printf("Multiplication is not possible\n");
    }
    
    return 0;
}
