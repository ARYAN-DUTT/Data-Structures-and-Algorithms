#include <iostream>
#include <cctype> // contains is digit, this is basically ctype.h library of C
using namespace std;

int main(){
  int stack[100];
  int top=-1;
  string s;
  char x;
  cout<<"Enter the expression"<<endl;
  getline(cin,s);
  for(int i=0; i<s.length(); i++){
    x = s[i];
    if(isdigit(x)){
      stack[++top] = x - '0';
    } else {
      int val2 = stack[top--];
      int val1 = stack[top--];
      int res = 0;

      switch(x){
        case '+': res = val1 + val2; break;
        case '-': res = val1 - val2; break;
        case '*': res = val1 * val2; break;
        case '/': res = val1 / val2; break;
      }
      stack[++top] = res;
    }
  }
  cout<< "Answer : "<<stack[top]<<endl;
}