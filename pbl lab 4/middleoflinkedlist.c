#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to find the middle element
void findMid(struct Node* head) {
    struct Node *fNode = head, *sNode = head;
    while (fNode != NULL && fNode->next != NULL) {
        sNode = sNode->next;
        fNode = fNode->next->next;
    }
    if (sNode != NULL) {
        printf("\nMiddle Element is: %d\n", sNode->data);
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    // Get the number of nodes to insert
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Insert nodes based on user's choice
    for (int i = 1; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("\nFinal Linked List: ");
    printList(head);

    findMid(head);

    return 0;
}
