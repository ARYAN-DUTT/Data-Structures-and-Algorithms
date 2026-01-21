#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
  char infix[50], postfix[50], stk[50];
  int top = -1, j = 0;
  printf("Enter infix expression: ");
  scanf("%s", infix);  //(a + b) * c
  int prec;
  for(int i=0; infix[i]!='\0'; i++){
    char ch = infix[i];
    if(isalnum(ch)){
      postfix[j++]=ch;
    } else if(ch=='('){
      stk[++top]=ch;
    } else if(ch==')'){
      while(top!=-1 && stk[top]!='('){
        postfix[j++]=stk[top--];
      }
      if(top!=-1) top--;
    }
    else {
      if(ch=='^') prec=3;
      else if(ch=='+' || ch=='-') prec=1;
      else if(ch=='*' || ch=='/') prec=2;
      else prec=0;
      while(top!=-1){
        char topOp = stk[top];
        int topPrec;
        if(topOp=='+' || topOp=='-') topPrec=1;
        else if(topOp=='*' || topOp=='/') topPrec=2;
        else topPrec=0;
        if(topPrec >= prec){
          postfix[j++]=stk[top--];
        } else {
          break;
        }
      }
      stk[++top]=ch;
    }
}
  while(top!=-1) postfix[j++]=stk[top--];
  postfix[j]='\0';
  printf("Postfix expression: %s\n", postfix);
  return 0;
}
// THIS CONVERTS INFIX TO POSTFIX