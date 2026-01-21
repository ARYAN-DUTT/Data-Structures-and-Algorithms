#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *reverse(struct Node *head)
{
  struct Node *prev = NULL, *curr = head, *next = NULL;

  while (curr != NULL)
  {
    next = curr->next; // store next
    curr->next = prev; // reverse link
    prev = curr;       // move prev
    curr = next;       // move curr
  }
  return prev; // new head
}

void printList(struct Node *head)
{
  while (head != NULL)
  {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

struct Node *insert(struct Node *head, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

int main()
{
  struct Node *head = NULL;

  head = insert(head, 10);
  head = insert(head, 20);
  head = insert(head, 30);

  printf("Original List:\n");
  printList(head);

  head = reverse(head);

  printf("Reversed List:\n");
  printList(head);

  return 0;
}
