// 1 for insert at begininng.
// 2 for insert at the end.
// 3 for insert at position.
// 4 for displaying the list.
// 5 for exiting.

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *newnode(int val){
   
}

void insertEnd(struct node **beg, int val){

}

void deleteEnd(struct node **beg, int val){

}

void deleteAtPos(struct node **beg, int index){

}

void display(struct node *beg){

}

int main(){
  struct node *start = NULL;
  int x,n;
  scanf("%d %d",x,n);
  while(x!=5){
    switch(x){
      case 1:
      
        break;
      case 2:
      
        break;
      case 3:
      
        break;
      case 4:
      
        break;
      case 4:
      
        break;
      case 5:
        printf("Exiting");
        break;
    }
    scanf("%d %d",x,n);
  }
}