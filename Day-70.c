#include <stdio.h>
#include <limits.h>

#define MAX 100

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(Edge edges[], int n, int m, int src) {
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    printf("Initial distances:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        printf("\nIteration %d:\n", i);

        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                printf("Updated dist[%d] = %d via edge (%d -> %d)\n", v, dist[v], u, v);
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("\nGraph contains NEGATIVE WEIGHT CYCLE!\n");
            return;
        }
    }

    // Final distances
    printf("\nFinal shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d -> INF\n", i);
        else
            printf("Node %d -> %d\n", i, dist[i]);
    }
}

// Main function
int main() {
    int n = 5;  // vertices
    int m = 8;  // edges

    Edge edges[] = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    int source = 0;

    bellmanFord(edges, n, m, source);

    return 0;
}