#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// Function for Topological Sort
void topologicalSort(int adj[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int i, j;

    // Calculate in-degree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("In-degree of vertices:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: %d\n", i, indegree[i]);
    }

    // Enqueue vertices with 0 in-degree
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    printf("\nTopological Order: ");

    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
        count++;
    }

    // Check for cycle
    if (count != n) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(adj, n);

    return 0;
}