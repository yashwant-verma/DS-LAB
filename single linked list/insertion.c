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

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
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

// Function to insert a node at the ith position of the linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the insertion functions
int main() {
    struct Node* head = NULL;
    int n, data, choice, position;

    // Get the number of nodes to insert
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Insert nodes based on user's choice
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        printf("Where do you want to insert the node?\n");
        printf("1. At the Beginning\n");
        printf("2. At the End\n");
        printf("3. At the ith Position\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = insertAtBeginning(head, data);
                break;
            case 2:
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                i--; // To retry for invalid choice
        }
        // Print the current linked list after each insertion
        printf("Updated Linked List: ");
        printList(head);
    }

    // Final linked list
    printf("\nFinal Linked List: ");
    printList(head);

    return 0;
}
