/*Write a C program that performs the addition of two matrices. The program should:
● Take matrix dimensions (rows and columns) from the user.
● Input two matrices from the user.
● Add them and display the resulting matrix
*/


#include<stdio.h>

int main(){

    int arr1[20][20],r,c,i,j,arr2[20][20],sum[20][20];
    printf("Enter the number of rows :\n");
    scanf("%d",&r);
    printf("Enter the number of column :\n");
    scanf("%d",&c);

    printf("Enter the elememts of First matrix :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter the elememts of second matrix :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("Sum of matrix :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d 3",sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}