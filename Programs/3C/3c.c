//Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
// a. Create a Graph of N cities using Adjacency Matrix.
// b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS method
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX], n, visited[MAX];

void createGraph() {
  int i, j;

  printf("Enter the number of cities: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }
}

void DFS(int start) {
  int i;

  printf("%d\t", start + 1);
  visited[start] = 1;

  for (i = 0; i < n; i++) {
    if (adj[start][i] == 1 && !visited[i]) {
      DFS(i);
    }
  }
}

void BFS(int start) {
  int i, queue[MAX], front = -1, rear = -1;

  printf("%d\t", start + 1);
  visited[start] = 1;
  queue[++rear] = start;

  while (front != rear) {
    start = queue[++front];

    for (i = 0; i < n; i++) {
      if (adj[start][i] == 1 && !visited[i]) {
        printf("%d\t", i + 1);
        visited[i] = 1;
        queue[++rear] = i;
      }
    }
  }
}

int main() {
  int i, start;

  createGraph();

  printf("Enter the starting node: ");
  scanf("%d", &start);
  start--;

  printf("\nNodes reachable using DFS: \n");
  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }
  DFS(start);

  printf("\nNodes reachable using BFS: \n");
  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }
  BFS(start);

  return 0;
}
