#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    int graph[100][100] = {0};

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges and weights:\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[100] = {0};
    int minEdge[100];
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        minEdge[i] = INT_MAX;
    }

    minEdge[1] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;

        for (int i = 1; i <= n; i++) {
            if (!selected[i] && (u == -1 || minEdge[i] < minEdge[u])) {
                u = i;
            }
        }

        selected[u] = 1;
        totalWeight += minEdge[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !selected[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    printf("Total weight of MST: %d", totalWeight);

    return 0;
}