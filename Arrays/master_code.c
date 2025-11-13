// Write a program to perform a specific set of operations over the array, initially array contains 10 elements. First you need to print all the elements and the even indexes. Secondly, print all the elements having odd indexes. Thirdly, insert 44 at 7th posittion, insert 99 at 2nd position, delete the element from the end, insert the element 100 at 5th position, delete the beginning element. insert 199 at 8th position. print the complete array.

#include <stdio.h>
int insert(int arr[], int num, int p, int n){
  for(int i=n;i>=p;i--){
    arr[i]=arr[i-1];
  }
  arr[p]=num;
  return n+1;
}
int delete(int arr[], int p, int n){
  for(int i=p; i<n-1; i++){
    arr[i]=arr[i+1];
  }
  return n-1;

}
int main(){
    int arr[100] = {1,2,3,4,5,6,7,8,9,10};
    int n=10;
    printf("Even indexes");
    for(int i=0; i<n; i++){
      if(i%2==0){
        printf("%d ",arr[i]);
      }
    }
    printf("Odd indexes");
    for(int i=0; i<n; i++){
      if(i%2!=0){
        printf("%d ",arr[i]);
      }
    }
    printf("\n");
    n=insert(arr,44,7,n);

    for(int i=0; i<n;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");

    n=insert(arr,99,2,n);

    for(int i=0; i<n;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");

    n=delete(arr,n-1,n);

    for(int i=0; i<n;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");

    n=insert(arr,100,5,n);
    for(int i=0; i<n;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");

    n=delete(arr,0,n);
    for(int i=0; i<n;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");
    n=insert(arr,199,8,n);
    for(int i=0; i<n;i++){
    printf("%d ",arr[i]);
  }
  }