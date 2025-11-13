#include <stdio.h>
#include <stdlib.h>
struct node{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *createNode(int val){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data=val;
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}
void *insertBeg(struct node **start, struct node **last,int val){
  struct node *newNode = createNode(val);
  if(*start==NULL){
    *start=newNode;
    *last=newNode;
  }
  else {
    newNode->next=*start;
    (*start)->prev=newNode;
    *start=newNode;
  }
}
void printForward(struct node *start){
  while(start!=NULL){
    printf("%d ",start->data);
    start=start->next;
  }
}

void printBackward(struct node *last){
    while(last!=NULL){
        printf("%d ",last->data);
        last=last->prev;
    }
}
void *insertEnd(struct node **start, struct node **last, int val){
  struct node *newNode = createNode(val);
  if(*start==NULL){
    *start=newNode;
    *last=newNode;
  }
  else {
    (*last)->next=newNode;
    newNode->prev=*last;
    *last=newNode;
  }
}

void deleteBeg(struct node **start, struct node **last){
    if(*start==NULL){
        printf("The linkedlist is already empty");
    } else if(*start==*last){
        *start=NULL;
        *last=NULL;
    } else{
    *start=(*start)->next;
    (*start)->prev=NULL;
    }
}

void deleteEnd(struct node **start, struct node **last){
    if(*start==NULL){
        printf("The linkedlist is already empty");
    } else if(*start==*last){
        *start=NULL;
        *last=NULL;
    } else{
    *last=(*last)->prev;
    (*last)->next=NULL;
    }
}

void search(struct node **start, struct node **last, int val){
    struct node *ptr = *start;

    while (ptr != NULL) {
        if (ptr->data == val) {
            if (ptr->prev == NULL) {
                deleteBeg(start, last);
            }
            else if (ptr->next == NULL) {
                deleteEnd(start, last);
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
            }
            return;
        }
        ptr = ptr->next;
    }

    printf("Value %d not found in the list\n", val);
}


int main(){
  struct node *start = NULL;
  struct node *last = NULL;
  int val;
  scanf("%d",&val);
  while(val!=-1){
    insertBeg(&start,&last,val);
    //insertEnd(&start,&last,val);
    scanf("%d",&val);
  }
  printForward(start);
  printf("\n");
  printForward(start);
  printf("\n");
  //printBackward(last);
//   deleteBeg(&start,&last);
//   deleteEnd(&start,&last);
  printf("Enter the key you want to search: ");
  scanf("%d",& val);
  search(&start,&last, val);
  printForward(start);
  printf("\n");
}
/* Things Done */ 
//insert at beginning
//insert at end
//print forward
//print backward
//search and delete