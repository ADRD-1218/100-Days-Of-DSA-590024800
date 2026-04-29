#include <stdio.h>

int main()
{
    int n, i, j, k;
    int graph[100][100];
    int INF = 99999;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    printf("Use -1 for no direct edge\n\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);

            if(graph[i][j] == -1 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("\nStarting Floyd Warshall Algorithm...\n");

    for(k = 0; k < n; k++)
    {
        printf("\nUsing vertex %d as intermediate:\n", k);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}