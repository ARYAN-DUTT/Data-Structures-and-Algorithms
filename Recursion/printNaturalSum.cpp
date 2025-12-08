#include <iostream>
using namespace std;

int sumTill(int n){
  if(n==1){
    return 1;
  }
  return n + sumTill(n-1);
}

int main(){
  int n;
  cin>>n;
  int sum = sumTill(n);
  cout<<sum;
}