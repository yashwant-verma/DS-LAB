/*Q2) Deletion in an array
Requirements:
1. Define an array that can store up to 10 natural numbers.
2. Allow the user to input n numbers into the array, where n is less than or equal
to 10.
3. Take one input from the user: choice.
○ choice: Represents the operation to be performed.
4. Based on the value of choice, perform the following operations:
○ If choice = 1, delete the element at the beginning of the array.
○ If choice = 2, delete the element at the end of the array.
○ If choice = 3, ask the user for a location i and delete the element at
the ith location of the array (0-based index).
5. After performing the deletion, display the updated array.
6. If the deletion is not possible (e.g., array is empty or an invalid location is
provided), print "Can't delete".
Output:
Display the updated array after the deletion, or print "Can't delete" if the operation is
not feasible.*/




#include <stdio.h>

int main() {
    int arr[10], n, choice, i, pos;
    printf("Enter the number of elements (up to 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Number of elements should be less than or equal to 10.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter your choice (1: delete at beginning, 2: delete at end, 3: delete at specific location): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (n == 0) {
                printf("Can't delete\n");
            } else {
                for (i = 0; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
            }
            break;
        case 2:
            if (n == 0) {
                printf("Can't delete\n");
            } else {
                n--;
            }
            break;
        case 3:
            printf("Enter the location (0-based index) to delete: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) {
                printf("Can't delete\n");
            } else {
                for (i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
            }
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    if (n == 0) {
        printf("Array is empty\n");
    } else {
        printf("Updated array:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
