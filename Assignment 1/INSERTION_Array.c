/*Q1) Insertion in an array
Requirements:
1. Define an array that can store up to 10 natural numbers.
2. Allow the user to input n numbers into the array, where n is less than or equal
to 10.
3. Take two inputs from the user: choice and data.
○ choice: Represents the operation to be performed.
○ data: Represents the element to be inserted.
4. Based on the value of choice, perform the following operations:
○ If choice = 1, insert the element data at the beginning of the array.
○ If choice = 2, insert the element data at the end of the array.
○ If choice = 3, ask the user for a location i and insert the element
data at the ith location of the array (0-based index).
5. After performing the insertion, display the updated array.
6. If the insertion is not possible (e.g., array is full or an invalid location is
provided), print "Can't insert".
Output:
Display the updated array after the insertion, or print "Can't insert" if the operation is
not feasible*/





// SOLUTION 

#include <stdio.h>

int main() {
    int arr[10], n, choice, data, i, pos;

    printf("Enter the number of elements (<=10)");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter choice (1: Insert at beginning, 2: Insert at end, 3: Insert at position): ");
    scanf("%d", &choice);
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);

    if (n >= 10) {
        printf("Can't insert\n");
    } else if (choice == 1) {
        for (i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = data;
        n++;
    } else if (choice == 2) {
        arr[n] = data;
        n++;
    } else if (choice == 3) {
        printf("Enter the index value where you want to insert:");
        scanf("%d", &pos);
        if (pos < 0 || pos > n) {
            printf("Can't insert\n");
        } else {
            for (i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = data;
            n++;
        }
    } else {
        printf("Invalid choice\n");
    }

    if (n <= 10) {
        printf("Updated array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
