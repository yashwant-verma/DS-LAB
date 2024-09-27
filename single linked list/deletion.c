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
    head = newNode;
    return head;
}

// Function to delete a node at the beginning of the linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end of the linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at the ith position of the linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
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
        printf("Updated Linked List after insertion: ");
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
        printf("Updated Linked List after deletion: ");
        printList(head);
    }

    // Final linked list
    printf("\nFinal Linked List: ");
    printList(head);

    return 0;
}
