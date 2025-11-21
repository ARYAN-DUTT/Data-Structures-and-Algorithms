#include <stdio.h>
int main(){
  int a1[100]={1,2,8,9,10};
  int a2[100]={1,2,8,78,90,88};
  int a3[100];
  int n1=5,n2=6;
  int i=0,j=0,k=0;
  while(i<n1 && j<n2){
    if(a1[i]<a2[j]){
      a3[k]=a1[i];
      k++;
      i++;
    }
    else{
      a3[k]=a2[j];
      k++;
      j++;
    }
  }
  while(j<n2){
    a3[k]=a2[j];
    j++;
    k++;
  }
  while(i<n1){
    a3[k]=a2[i];
    i++;
    j++;
  }
  for(int z=0; z<k; z++){
    printf("%d ",a3[z]);
  }
}



