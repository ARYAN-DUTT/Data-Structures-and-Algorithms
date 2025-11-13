#include<stdio.h>
int main(){
  int arr[100]={5,4,3,8,3};
  int n=5;
  int max=arr[0];
  for(int i=1;i<n;i++){
    if(arr[i]>arr[i-1]){
      max=arr[i];
    }
  }
  printf("Max height is : %d\n",max);
  //instead of max%2, we can use.....
  if(max & 1){
    printf("Odd");
  }
  else{
    printf("Even");
  }
}