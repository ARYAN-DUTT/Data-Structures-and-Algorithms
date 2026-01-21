// This code is in c++

#include <iostream>
#include <string>
using namespace std;

int main(){
  int stack[100];
  int top = -1;
  string s;
  cout<< "Enter the postfix expression : "<<endl;
  getline(cin,s);
  for(int i=0; s[i]!='\0'; i++){
    char x = s[i];
    if(x==' '){
      continue;
    } else if(isdigit((unsigned char)x)){
      int num = 0;
      while(isdigit((unsigned char)s[i])){
        num = num*10 + (s[i]-'0');
        i++;
      }
      stack[++top]=num;
    } else {
      char op = s[i];
      int val2 = stack[top--];
      int val1 = stack[top--];
      int res = 0;
      switch(op){
        case '+': res = val1 + val2; break;
        case '-': res = val1 - val2; break;
        case '*': res = val1 * val2; break;
        case '/': res = val1 / val2; break;
      }
      stack[++top] = res;
    }
  } cout<<"Result: "<<stack[top]<<endl;

}