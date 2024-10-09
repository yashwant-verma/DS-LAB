// STACK IMPLEMENTATION USING LINKED LISTS
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void peek() {
    if (top == NULL) {
        printf("Stack underflow\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void pop() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("Stack underflow.\n");
    } else {
        top = top->next;
        free(temp);
    }
}

void isEmpty() {
    if (top == NULL) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void isFull() {
    printf("False\n");
}

void display() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("Stack underflow.\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int nop, x;
    printf("Enter the number of operations: ");
    scanf("%d", &nop);
    for (int i = 0; i < nop; i++) {
        printf("\nEnter the operation (1.Push, 2.Pop, 3.Peek, 4.isEmpty, 5.isFull): ");
        int op;
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            default:
                printf("Invalid Choice.\n");
        }
    }
    printf("\nFinal Stack is: ");
    display();
    return 0;
}
