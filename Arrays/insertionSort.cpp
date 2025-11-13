#include <iostream>
using namespace std;
void print(int arr[], int n){
    for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}
void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j=i;
        for(;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  insertionSort(arr,n);
  print(arr,n);
  return 0;
}