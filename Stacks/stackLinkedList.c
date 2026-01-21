// This is the code for linked list representation of stack.

#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *next;
};

struct Node *createNode(int val){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data=val;
  newNode->next=NULL;
  return newNode;
}

void push(struct Node **top, int val){
  // Basically insert at end.
  struct Node *newNode = createNode(val);
  if(*top==NULL){
    *top=newNode;
  } else {
    struct Node *temp = *top; 
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
  }
}

void pop(struct Node **top){
  if(*top==NULL){
    printf("Stack is Empty.");
    return;
  } else if((*top)->next==NULL){
    printf("Popped : %d\n",(*top)->data);
    *top=NULL;
  } else {
    struct Node *temp = *top;
    while(temp->next->next!=NULL){
      temp=temp->next;
    }
    printf("Popped : %d\n",temp->next->data);
    temp->next=NULL;
  }
}

int main(){
  struct Node *top = NULL;
  int n=0;
  while(n!=-1){
    scanf("%d",&n);
    if(n!=-1){
      push(&top,n);
    }
  }

  while(top!=NULL){
    pop(&top);
  }
}