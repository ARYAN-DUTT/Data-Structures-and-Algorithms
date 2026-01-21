// bellman ford  #include <stdio.h>
#include <limits.h>

#define V 5
#define INF 99999

void bellmanFord(int graph[V][V], int src)
{
  int dist[V];

  // Step 1: Initialize distances
  for (int i = 0; i < V; i++)
    dist[i] = INF;

  dist[src] = 0;

  // Step 2: Relax every edges V-1 times
  for (int k = 1; k <= V - 1; k++)
  {
    for (int u = 0; u < V; u++)
    {
      for (int v = 0; v < V; v++)
      {

        // Check if edge exists
        if (graph[u][v] != 0 && dist[u] != INF &&
            dist[u] + graph[u][v] < dist[v])
        {

          dist[v] = dist[u] + graph[u][v];
        }
      }
    }
  }

  // Step 3: Check for negative cycle
  for (int u = 0; u < V; u++)
  {
    for (int v = 0; v < V; v++)
    {

      if (graph[u][v] != 0 && dist[u] != INF &&
          dist[u] + graph[u][v] < dist[v])
      {

        printf("Negative weight cycle detected\n");
        return;
      }
    }
  }

  // Print result
  printf("Vertex\tDistance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d\t%d\n", i, dist[i]);
}

int main()
{
  int graph[V][V] = {
      {0, -1, 4, 0, 0},
      {0, 0, 3, 2, 2},
      {0, 0, 0, 0, 0},
      {0, 1, 5, 0, 0},
      {0, 0, 0, -3, 0}};

  bellmanFord(graph, 0);
  return 0;
}