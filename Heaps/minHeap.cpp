#include <iostream>
using namespace std;
#define MAX 100
int size = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify_up(int heap[], int pos)
{
  int parent = pos / 2;
  while (pos > 1)
  {
    if (heap[pos] < heap[parent])
    {
      swap(&heap[pos], &heap[parent]);
      pos = parent;
      parent = pos / 2;
    }
    else
    {
      break;
    }
  }
}

void del(int heap[])
{
  int i = 1;
  heap[1] = heap[size];
  size--;
  while (2 * i <= size)
  {
    int child = 2 * i;
    if (child + 1 <= size && heap[child + 1] < heap[child])
    {
      child = child + 1;
    }
    if (heap[i] <= heap[child])
    {
      break;
    }
    swap(&heap[i], &heap[child]);
    i = child;
  }
}

void insert_heap(int heap[], int val)
{
  heap[++size] = val;
  heapify_up(heap, size);
}

int main()
{
  int heap[MAX] = {0};
  int n;
  int val;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> val;
    insert_heap(heap, val);
  }
  del(heap);
  for (int i = 1; i <= n; i++)
  {
    cout << heap[i] << " ";
  }
}