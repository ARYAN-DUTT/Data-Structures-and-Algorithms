// enqueue to push
// front <= rear to top!=-1
// dequeue to pop

#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int adj[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int n;   // number of vertices

// Push function
int push(int value){
    if(top < MAX_SIZE - 1){
        stack[++top] = value;
        return 1;
    }
    return 0;
}

// Pop function
int pop(){
    if(top != -1){
        return stack[top--];
    }
    return -1;
}

// DFS using stack
void DFS(int start){
    printf("DFS Traversal: ");

    push(start);
    visited[start] = 1;

    while(top != -1){
        int current = pop();
        printf("%d ", current);

        // Push adjacent nodes (reverse order for correct DFS)
        for(int i = n - 1; i >= 0; i--){
            if(adj[current][i] == 1 && !visited[i]){
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    DFS(start);

    return 0;
}
