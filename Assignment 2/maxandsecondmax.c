/*
Write a C program to find the maximum and second maximum element in an array of
size n using a single loop.
*/


//Solution----

#include <stdio.h>


int main() {
    int n, i, arr[50];
    int max1, max2;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

     if(arr[0]<arr[1]){
        max1=arr[1];
        max2=arr[0];
     } else{
        max1=arr[0];
        max2=arr[1];
     }
    
    for (i = 2; i < n; i++){
        if (arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] < max1) {
            max2 = arr[i];
        }
    }

    printf("The maximum element is %d\n", max1);
    printf("The second maximum element is %d", max2);

    return 0;
}
