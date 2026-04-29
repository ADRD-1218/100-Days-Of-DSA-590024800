#include <stdio.h>
#include <limits.h>

int main()
{
    int n, m, i, j, u, v, w, source;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int graph[100][100];

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    printf("\nEnter edges (u v w):\n");
    for(i = 0; i < m; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;   // Remove if directed graph
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &source);

    int dist[100], visited[100];

    for(i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    printf("\nStarting Dijkstra Algorithm...\n");

    for(i = 1; i <= n; i++)
    {
        int min = INT_MAX, node = -1;

        for(j = 1; j <= n; j++)
        {
            if(visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                node = j;
            }
        }

        visited[node] = 1;

        printf("\nVisited Vertex %d , Distance = %d\n", node, dist[node]);

        for(j = 1; j <= n; j++)
        {
            if(graph[node][j] != INT_MAX && visited[j] == 0)
            {
                if(dist[node] + graph[node][j] < dist[j])
                {
                    dist[j] = dist[node] + graph[node][j];
                    printf("Updated Distance of Vertex %d = %d\n", j, dist[j]);
                }
            }
        }
    }

    printf("\nShortest Distances from Source %d:\n", source);

    for(i = 1; i <= n; i++)
    {
        printf("Vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}