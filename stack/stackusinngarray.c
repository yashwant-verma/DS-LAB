#include <stdio.h>
#define MAX 5

int top = -1;

void isempty(int arr[]) {
    if (top == -1) {
        printf("Stack is empty\n");
    }
}

void isfull(int arr[]) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    }
}

int peek(int arr[]) {
    if (top == -1) {
        printf("Array underflow\n");
        return -1;
    } else {
        return arr[top];
    }
}

void push(int arr[], int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        arr[++top] = x;
    }
}

int pop(int arr[]) {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return arr[top--];
    }
}

void printarray(int arr[]) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX], i;
    int n;

    printf("Enter the number of operations you want to do: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int op;
        printf("Enter the choice:\n1. Push element\n2. Peek the element\n3. Pop the element\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the element to push: ");
                int element;
                scanf("%d", &element);
                push(arr, element);
                break;
            case 2:
                printf("Top element is: %d\n", peek(arr));
                break;
            case 3:
                printf("Popped element is: %d\n", pop(arr));
                break;
            default:
                printf("Enter a valid choice\n");
        }
    }

    printarray(arr);

    return 0;
}
