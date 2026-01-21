//DFS can be obtained from BFS by replacing the queue with a stack, i.e., replacing enqueue with push and dequeue with pop, along with reversing the adjacency traversal order. and print when popped

#include <iostream>
using namespace std;
#define MAX 7
int stk[MAX];
int visited[MAX] = {0};
int top = -1;


void push(int val){
  if(top==MAX-1){
    cout<<"Overflow"<<endl;
    return;
  }
  stk[++top] = val;

}

int pop(){
  if(top==-1){
    cout<<"Underflow"<<endl;
    return -1;
  }

  return stk[top--];
}

bool isempty(){
  return top==-1;
}

int main(){
  int i = 0;
  visited[i] = 1;
  push(i);
  int graph[MAX][MAX] = {
    {0,1,1,1,0,0,0},//
    {1,0,0,1,0,0,0},
    {1,0,0,1,1,0,0},
    {1,1,1,0,1,0,0},//
    {0,0,1,1,0,1,1},//
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
  while(!isempty()){
    int node = pop();
    cout<<node<<" ";
    for(int j = 0; j<=MAX-1; j++){
      if(graph[node][j]==1 && visited[j]==0){
        visited[j] = 1;
        push(j);
      }
    }
  }

}