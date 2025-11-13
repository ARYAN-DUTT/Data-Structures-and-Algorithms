// This is my custom version of singly linked list code
#include <stdio.h>
#include <stdlib.h>
struct node{
  // This is basically a custom data type
  int data;
  struct node *next;
  // this means that next is a pointer to another whole(full) struct node.
  // you could derefence the next to get the contents of the next node.
};

struct node *createNode(int value){
  // "struct node *" tells that we want to return a pointer
  struct node *new = (struct node *)malloc(sizeof(struct node));
  (*new).data=value;
  // this is same as new->data=value;
  (*new).next=NULL;
  return new;
}

struct node *insertBeg(struct node *beg, int value){
  // "struct node *" tells that we want to return a pointer
  struct node *newNode = createNode(value);
  if(beg==NULL){
    beg=newNode;
    //beginning is set to newNode for empty linkedlist
    //Next of the the first element is already null (from createNode function)
  } else{
    (*newNode).next=beg;
    // next of the newNode is made beg (Old start)
    beg=newNode;
    // newNode is basically changed to the (New start)
  }
  return beg;
}

void print_LL(struct node *beg){
  while(beg!=NULL){
    printf("%d ",(*beg).data);
    beg=(*beg).next;
  }
}

int main(){
  struct node *start = NULL;
  int val;
  scanf("%d",&val);
  while(val!=-1){
    start = insertBeg(start,val);
    //this start is a pointer to a node, we are sending a pointer.
    //but this is not call by reference because C always passes arguments by value (it copies the argument).
    scanf("%d",&val);
  }
  print_LL(start);

}