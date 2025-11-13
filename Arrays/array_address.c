#include <stdio.h>
int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  for(int i = 0; i < 5; i++) {
    printf("Address of arr[%d]: %p\n", i, (void*)&arr[i]);
  }
}