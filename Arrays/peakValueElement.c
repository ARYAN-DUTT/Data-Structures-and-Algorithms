#include <stdio.h>
int main(){
  int arr[6]={1,2,3,1,5,7};
  int n=6;
  for(int i=1; i<n-1; i++){
    if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
      printf("%d is the peak element",arr[i]);
    }
  }
}