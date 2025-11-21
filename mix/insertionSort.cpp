#include <iostream>
using namespace std;
int main(){
  int arr[10]= {6,5,3,2,1,7,4,9,8,10};
  int n=10;
  for(int i = 1; i<n; i++){
    int j=i;
    for(;j>0;j--){
        if(arr[j]<arr[j-1]){
          int temp = arr[j];
          arr[j]=arr[j-1];
          arr[j-1]=temp;
        }
    }
  }
  for(int i=0; i<n; i++){
      cout<<arr[i]<<" ";
  }
}