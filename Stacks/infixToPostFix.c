#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
  char infix[50], postfix[50], stack[50];
  int top = -1, j = 0;
  printf("Enter infix expression: ");
  scanf("%s", infix);
  for(int i=0; infix[i]!='\0'; i++){
    char ch = infix[i];
    if(isalnum(ch)){
      postfix[j++]=ch;
    } else if(ch=='('){
      stack[++top]=ch;
    } 
    else if(ch==')'){
      while(top!=-1 && stack[top]!='('){
        postfix[j++]=stack[top--];
      }
      if(top!=-1) top--;
    } 
    else {
      while(top!=-1 && (stack[top]=='*' || stack[top]=='/' || (stack[top]=='+' || stack[top]=='-') && (ch=='+' || ch=='-'))){
        postfix[j++]=stack[top--];
      }
      stack[++top]=ch;
    }
  }
  while(top!=-1) postfix[j++]=stack[top--];
  postfix[j]='\0';
  printf("Postfix expression: %s\n", postfix);
  return 0;
}