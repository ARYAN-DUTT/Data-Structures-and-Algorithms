#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int key){
  int index = key % SIZE;
  if(hashTable[index]==-1){
    hashTable[index]=key;
  } else {
    for(int i = 1; i<SIZE; i++){
      int newIndex = (index + 1)%SIZE;
      if(hashTable[newIndex]==-1){
        hashTable[newIndex]=key;
        return;
      }
    }
    printf("Hash Table Overflow\n");
  }
}

void display(){
  for(int i=0; i<SIZE; i++){
    if(hashTable[i]!=-1){
      printf("Index %d: %d\n", i, hashTable[i]);
    } else {
      printf("Index %d: Empty\n", i);
    }
  }
}

int main(){
  memset(hashTable, -1, sizeof(hashTable));
  int n, key;
  printf("Enter number of keys to insert: ");
  scanf("%d", &n);
  printf("Enter the keys:\n");
  for(int i=0; i<n; i++){
    scanf("%d", &key);
    insert(key);
  }
  printf("Hash Table:\n");
  display();
  return 0;
}