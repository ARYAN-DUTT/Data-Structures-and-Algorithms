#include <stdio.h>
#include <stdbool.h> // needed for boolean type
//#define max_cap 50;
int max_cap;
int top=-1;
void push(int stk[], int val){
  if(top==max_cap-1)
    printf("stack is full. Overflow");
  else{
    top++;
    stk[top]=val;
  }
}
void pop(int stk[]){
  if(top==-1)
    printf("stack is empty. Underflow");
  else{
    printf("%d ",stk[top]);
    top--;
  }
}
int isEmpty(int stk[]){
  if(top==-1)
    return 1;
  else
    return 0;
}
int ifFull(int stk[]){
  if(top==max_cap-1)
    return 1;
  else
    return 0;
}

int main(){
  int stk[50];
  scanf("%d",&max_cap);
  int val;
  scanf("%d",&val);
  while(val!=-1){
    push(stk,val);
    scanf("%d",&val);
  }
  if(isEmpty(stk))
    printf("Stack is empty\n");
  else
    printf("Stack is not empty\n");
  if(ifFull(stk))
    printf("Stack is full\n");
  else
    printf("Stack is not full\n"); 

  printf("Popping and Printing elements:\n");

  while(top!=-1){
    pop(stk);
  }
  return 0;
}