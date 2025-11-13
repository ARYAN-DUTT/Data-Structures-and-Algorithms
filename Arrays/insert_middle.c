#include <stdio.h>
int main(){
  int num,p,n=5;
  int arr[100]={1,2,3,4,5};
  printf("enter the number you want to add : ");
  scanf("%d",&num);
  printf("enter the position where you want to add : ");
  scanf("%d",&p);
  for(int i=n-1;i>=p;i--){
    arr[i+1]=arr[i];
  }
  arr[p]=num;
  for(int i=0; i<n+1;i++){
    printf("%d ",arr[i]);
  }
}
// num is the number to be added and p is the position where it is to be added
// Example input: num=100, p=2
// Example output: 1 2 100 3 4 5