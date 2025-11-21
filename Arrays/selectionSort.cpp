#include <iostream>
using namespace std;
int main(){
  int arr[10] = {75,1000,43,25,3,67,76,5,32,54};
  int n=10;
  for(int i=0; i<n; i++){
    int min=arr[i];
    int index=0;
    for(int j=i+1; j<n; j++){
        if(arr[j]<min){
          min=arr[j];
          index=j;
        }
    }
    if(index!=0){
      int temp = arr[i];
      arr[i] = min;
      arr[index] = temp;
    }
    index=0;
  }
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}