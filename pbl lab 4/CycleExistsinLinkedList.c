#include <stdio.h>
#include <stdlib.h>



struct Node {
  int data;
  struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
  /* allocate node */
  struct Node* new_node
    = (struct Node*)malloc(sizeof(struct Node));
  /* put in the data */
  new_node->data = new_data;
  /* link the old list of the new node */
  new_node->next = (*head_ref);
  /* move the head to point to the new node */
  (*head_ref) = new_node;
}
int detectLoop(struct Node* list)
{
  struct Node *slow_p = list, *fast_p = list;
  while (slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;
    if (slow_p == fast_p) {
      return 1;
    }
  }
  return 0;
}
int main()
{
  struct Node* head = NULL;
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);
  /* Create a loop for testing */
  head->next->next->next->next = head;
  if (detectLoop(head))
    printf("Loop found");
  else
    printf("No Loop");
  return 0;
}