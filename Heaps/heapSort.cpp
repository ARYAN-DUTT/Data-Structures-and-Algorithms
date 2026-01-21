#include <iostream>
using namespace std;
#define MAX 100
int size = 0;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify_up(int heap[], int i){
  int parent = i / 2;
  while (i > 1){
    if (heap[parent] < heap[i]){
      swap(&heap[parent], &heap[i]);
      i = parent;
      parent = i / 2;
    } else {
      break;
    }
  }
}

void del(int heap[])
{
  int i = 1;
  int temp = heap[1];
  heap[1] = heap[size];
  heap[size] = temp;
  size--;

  while (2 * i <= size)
  {
    int child = 2 * i;
    if (child + 1 <= size && heap[child + 1] > heap[child])
    {
      child = child + 1;
    }
    if (heap[i] >= heap[child])
    {
      break;
    }
    swap(&heap[i], &heap[child]);
    i = child;
  }
}


void insert_heap(int heap[], int val){
  size++;
  heap[size] = val;
  heapify_up(heap, size);
}

int main(){
  int heap[MAX] = {0};
  int val;
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++){
    cin>>val;
    insert_heap(heap, val);
  }
  
  for (int i = 1; i <= n; i++)
  {
    del(heap);
  }
  for (int i = 1; i <= n; i++)
  {
    cout << heap[i] << " ";
  }
}
