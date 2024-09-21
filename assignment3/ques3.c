/*
Write a C program that finds the transpose of a given matrix. The program should:
● Take the matrix dimensions and the matrix itself as input from the user.
● Display the transpose of the matrix.

*/

#include<stdio.h>

int main(){

    int arr[50][50],c,r,i,j,trans[50][50];
    printf("Enter the number of rows :\n");
    scanf("%d",&r);
    printf("Enter the number of column :\n");
    scanf("%d",&c);
    

    printf("Enter the elememts of matrix :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            trans[j][i]=arr[i][j];
        }
    }
    printf("Transpose of mattrix :\n");
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}