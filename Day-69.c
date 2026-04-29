#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Min Heap Node
typedef struct {
    int node;
    int dist;
} HeapNode;

// Min Heap
typedef struct {
    HeapNode arr[MAX];
    int size;
} MinHeap;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap *h, int idx) {
    while (idx > 0 && h->arr[(idx - 1) / 2].dist > h->arr[idx].dist) {
        swap(&h->arr[(idx - 1) / 2], &h->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap *h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && h->arr[left].dist < h->arr[smallest].dist)
        smallest = left;

    if (right < h->size && h->arr[right].dist < h->arr[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&h->arr[idx], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// Insert into heap
void push(MinHeap *h, int node, int dist) {
    h->arr[h->size].node = node;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Remove min
HeapNode pop(MinHeap *h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Dijkstra function
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    printf("Processing nodes:\n");

    while (heap.size > 0) {
        HeapNode curr = pop(&heap);
        int u = curr.node;

        if (visited[u]) continue;
        visited[u] = 1;

        printf("Visited node %d with distance %d\n", u, curr.dist);

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    printf("Updated dist[%d] = %d\n", v, dist[v]);
                    push(&heap, v, dist[v]);
                }
            }
        }
    }

    printf("\nFinal shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }
}

// Main function
int main() {
    int n = 5;

    int graph[MAX][MAX] = {
        {0, 2, 4, 0, 0},
        {0, 0, 1, 7, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    int source = 0;

    dijkstra(graph, n, source);

    return 0;
}