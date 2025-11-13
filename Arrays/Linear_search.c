#include<stdio.h>
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
  int key,flag=0,index;
  scanf("%d",&key);
  for(int i=0; i<n; i++){
    if(arr[i]==key){
      flag=1;
      index=i;
      printf("Found at %d.",index);
    }
  }
  if(flag==0){
    printf("Not Found!");
  }
}