#include <stdio.h>

int lowerBound(int arr[], int n, int target) {

    int left = 0, right = n - 1, result = -1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= target) {
            result = mid;
            right = mid - 1;
        } 
        else {
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

    int target = 6;
    
    int index = lowerBound(arr, n, target);
    
    if (index != -1) {
        printf("Lower bound of %d is at index %d\n", target, index);
    } 
    else {
        printf("No element greater than or equal to %d exists\n", target);
    }

    return 0;
}
