#include <stdio.h>
int main(){
  int arr[100];
  int n;
  printf("Enter the number of elements in array : ");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(int i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter the key : ");
  int key;
  scanf("%d",&key);
  int lb=0,ub=n-1;
  int index=-1;
  int mid;
  while(lb<=ub){
      mid = ((lb+ub)/2);
      if(key==arr[mid]){
          index=mid;
          break;
      }
      else if(key>arr[mid]){
          lb=mid+1;
      }
      else if(key<arr[mid]){
          ub=mid-1;
      }
  }
  if(index==-1){
      printf("Not Found");
  }
  else{
      printf("Found at %d.",index);
  }
}