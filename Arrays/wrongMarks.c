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
  printf("Enter the rollNo of student with wrong marks : ");
  int roll;
  scanf("%d",&roll);
  printf("Enter correct marks: ");
  int correct;
  scanf("%d",&correct);
  arr[roll]=correct;
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);

  }
}