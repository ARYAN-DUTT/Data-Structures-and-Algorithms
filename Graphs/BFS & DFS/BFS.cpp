// Breadth First Sreach
// This is bassically c code with cout
// interconversion of these codes in c and c++ es easy
#include <iostream>
using namespace std;

#define MAX 7
int q[MAX];
int visited[MAX] = {0};
int front = -1;
int rear = -1;


void enqueue(int val){
  if(rear == MAX-1){
    cout<<"Queue Overflow"<<endl;
    return;
  }
  if(front == -1){
    front = 0;
  }
  q[++rear] = val;
}

int dequeue(){
  if(front == -1 || front > rear){
    cout<<"Queue Underflow"<<endl;
    return -1;
  }
  int temp = front;
  front++;
  return q[temp];
}

bool isempty(){
  if(front==-1 || front > rear){
    return 1;
  } else {
    return 0;
  }
}

int main(){
  int i = 0;
  visited[i] = 1;
  enqueue(i);
  int graph[MAX][MAX] = {
    {0,1,1,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,0,0,1,1,0,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
  cout<<i<<" ";
  while(!isempty()){
    int node = dequeue();
    for(int j = 0; j<MAX; j++){
      if(graph[node][j]==1 && visited[j]==0){
        visited[j] = 1;
        cout<<j<<" ";
        enqueue(j);
      }
    }
  }

}