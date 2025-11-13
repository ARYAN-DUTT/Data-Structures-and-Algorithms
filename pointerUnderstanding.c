#include <stdio.h>
int main(){
  int a=5;
  int *b=&a;
  int **c=&b;
  printf("%p\n",*c);
  printf("%p",b);
}