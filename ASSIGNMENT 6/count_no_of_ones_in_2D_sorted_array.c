#include <stdio.h>


int firstoneindex(int arr[], int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
            return mid;
        else if (arr[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int countones(int arr[20][20], int rows, int cols) {
    int totalones = 0;
    for (int i = 0; i < rows; i++) {
        int firstone = firstoneindex(arr[i], 0, cols - 1);
        if (firstone != -1) {
            totalones += (cols - firstone);
        }
    }
    return totalones;
}

int main() {

    int rows,cols;
    int arr[20][20];
    printf("Enter the no. of Rows:\n");
    scanf("%d",&rows);
    printf("Enter the no. of Cols:\n");  
    scanf("%d",&cols);
    
    printf("Enter the array elements:\n");

    for (int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int totalones = countones(arr, rows, cols);
    printf("Total number of 1's: %d\n", totalones);
    return 0;
}
