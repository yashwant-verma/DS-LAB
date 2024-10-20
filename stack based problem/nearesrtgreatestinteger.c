#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int arr[], int n, int nge[]) {
    int stack[n];   
    int top = -1; 
    
    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i]) {
            top--;
        }

        if (top != -1) {
            nge[i] = stack[top];
        } else {
            nge[i] = -1;  
        }

        top++;
        stack[top] = arr[i];
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  
    int nge[n];  

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nextGreaterElement(arr, n, nge);

    printf("NGE[] = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nge[i]);
    }
    
    return 0;
}