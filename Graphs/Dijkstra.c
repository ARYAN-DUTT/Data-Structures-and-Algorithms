// Wrote it myself

#include <stdio.h>
#define V 4
#define INF 9999

int findmin(int dist[], int visited[]){
  int min = INF;
  int index=-1;
  for(int i=0; i<V; i++){
    if(dist[i]<=min && visited[i]==0){
      min=dist[i];
      index=i;
    }
  }
  return index;
}

void dijkstra(int graph[V][V], int src){
  int dist[V];
  int visited[V]={0};

  for(int i=0; i<V; i++){
    dist[i]=INF;
  }
  dist[src] = 0;
  for(int count=0; count<=V-1; count++){
    int u = findmin(dist,visited);
    visited[u] = 1;
    for(int v=0; v<V; v++){
      if(
        !visited[v] &&
        graph[u][v] &&
        dist[u]!=INF &&
        dist[u] + graph[u][v] < dist[v]
      ){
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }
  printf("Vertex \t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

int main(){
  int graph[V][V] = {
      {0, 5, 0, 10},
      {0, 0, 3, 0},
      {0, 0, 0, 1},
      {0, 0, 0, 0}};
  dijkstra(graph,0);
  return 0;
}