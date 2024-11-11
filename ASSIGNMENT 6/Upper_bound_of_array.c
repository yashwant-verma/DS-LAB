/*Problem Statement: Implement a function to find the upper bound of a given
value in a sorted array. The upper bound is the index of the first element that is
strictly greater than a specified target value.*/


#include <stdio.h>

int upperbound(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {

    int arr[50];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the element of array\n");
    for (int i = 0 ; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int target = 4;
    
    int index = upperbound(arr, n, target);
    
    if (index != -1) {
        printf("Upper bound of %d is at index %d\n", target, index);
    } else {
        printf("No element strictly greater than %d exists\n", target);
    }
    
    return 0;
}
