#include <stdio.h>
int main(){
  char arr[5]={1,2,3,4,5};
  int n=5;
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
//1 2 3 4 5 will be printed

int main(){
  char arr[5]={'1','2','3','4','5'};
  int n=5;
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
//49 50 51 52 53 will be printed

int main(){
  int arr[5]={a,b,c,d,e};
  int n=5;
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
//This will give error as a,b,c,d,e are not defined

int main(){
  int arr[5]={'a','b','c','d','e'};
  int n=5;
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
//97 98 99 100 101 will be printed
