#include <stdio.h>
int main(){
    int arr[100] = {1, 2, 3, 4, 5};
    for(int i=5; i>=0; i--){
      arr[i+1]=arr[i];
    }
    arr[0]=100;
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
// 100 1 2 3 4 5 will be printed
// 100 is inserted at index 0 and rest of the elements are shifted to right