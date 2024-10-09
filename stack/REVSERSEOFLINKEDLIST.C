#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNodeAtEnd(struct Node* head, int data) {
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

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverse(struct Node* head) {
    struct Node *preNode = NULL, *currNode = head, *nextNode;
    while (currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = preNode;
        preNode = currNode;
        currNode = nextNode;
    }
    head = preNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        head = insertNodeAtEnd(head, data);
    }
    printf("\nFinal Linked List before reverse: ");
    displayList(head);
    printf("\nFinal Linked List after reverse: ");
    head = reverse(head);
    displayList(head);
    return 0;
}
