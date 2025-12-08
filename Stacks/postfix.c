#include <stdio.h>
#include <ctype.h> // contains isdigit function

int main(){
  char expr[50];
  int stack[50];
  int top=-1;
  printf("Enter postfix expression: ");
  scanf("%s",expr);
  for(int i=0; expr[i]!='\0'; i++){
    char ch = expr[i];
    if(isdigit(ch)){
      stack[++top] = ch - '0';
    }
    else{
      int val2 = stack[top--];
      int val1 = stack[top--];
      int res;
      switch(ch){
        case '+': res = val1 + val2; break;
        case '-': res = val1 - val2; break;
        case '*': res = val1 * val2; break;
        case '/': res = val1 / val2; break;
      }
      stack[++top] = res;
    }
  }
  printf("Result: %d\n", stack[top]);
  return 0;
}