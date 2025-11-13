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

void print(struct node *start){
  while(start!=NULL){
    printf("%d ",start->data);
    start=start->next;
  }
}

int main(){
  struct node *start = createNode(0);
  int val;
  scanf("%d",&val);
  while(val!=-1){
    start->next=insertBeg(start,val);
    scanf("%d",&val);
  }
  print(start);
  return 0;

}