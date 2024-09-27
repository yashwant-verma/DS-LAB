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

// Function to insert a node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

// Function to delete a node at the beginning of the circular linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    struct Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    free(toDelete);
    return head;
}

// Function to delete a node at the end of the circular linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct Node* toDelete = temp->next;
    temp->next = head;
    free(toDelete);
    return head;
}

// Function to delete a node at the ith position of the circular linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    struct Node* temp = head;
    for (int i = 0; temp->next != head && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Position out of bounds\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Main function to test the insertion and deletion functions
int main() {
    struct Node* head = NULL;
    int n, data, choice, position;

    // Get the number of nodes to insert at the beginning
    printf("Enter the number of nodes you want to insert at the beginning: ");
    scanf("%d", &n);

    // Insert nodes at the beginning
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
        // Print the current linked list after each insertion
        printf("Updated Circular Linked List after insertion: ");
        printList(head);
    }

    // Get the number of nodes to delete
    printf("\nEnter the number of nodes you want to delete: ");
    scanf("%d", &n);

    // Delete nodes based on user's choice
    for (int i = 0; i < n; i++) {
        printf("Where do you want to delete the node?\n");
        printf("1. At the Beginning\n");
        printf("2. At the End\n");
        printf("3. At the ith Position\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = deleteAtBeginning(head);
                break;
            case 2:
                head = deleteAtEnd(head);
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                i--; // To retry for invalid choice
        }
        // Print the current linked list after each deletion
        printf("Updated Circular Linked List after deletion: ");
        printList(head);
    }

    // Final linked list
    printf("\nFinal Circular Linked List: ");
    printList(head);

    return 0;
}
