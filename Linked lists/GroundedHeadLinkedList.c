#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *createNode(int val){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data=val;
  newNode->next=NULL;
  return newNode;
}

struct node *insertBeg(struct node *start, int val){
  start->data++;
  struct node *newNode = createNode(val);
  if(start->next==NULL){
    start->next=newNode;
  }
  else {
    newNode->next=start->next;
    start->next=newNode;
  }
  return newNode;
}

void insertEnd(struct node *start, int val){
  start->data++;
  struct node *newNode = createNode(val);
  if(start->next==NULL){
    start->next=newNode;
  } else {
    while(start->next!=NULL){
      start=start->next;
    }
    start->next=newNode;
  }
}

void deleteEnd(struct node *start){
  start->data--;
  if(start->next==NULL){
    printf("List is empty");
  } else{
    while(start->next->next!=NULL){
      start=start->next;
    }
  }
  start->next=NULL;
}
// delete beginning

void print(struct node *start){
  while(start!=NULL){
    printf("%d ",start->data);
    start=start->next;
  }
}

struct node* reverse(struct node *start){
  struct node *prev = NULL;
  struct node *curr = start;
  struct node *agla = start->next;
  while(curr!=NULL){
    curr->next=prev;
    prev=curr;
    curr=agla;
    if(agla==NULL){
      break;
    }
    agla = agla->next;
  }
  return prev;
}

int main(){
  struct node *start = createNode(0);
  int val;
  scanf("%d",&val);
  while(val!=-1){
    start->next = insertBeg(start, val);
    //insertEnd(start,val);
    scanf("%d",&val);
  }
  //deleteEnd(start);
  start = reverse(start);
  print(start);
  return 0;
}