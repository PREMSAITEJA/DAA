#include <stdio.h>
#define INF 99999
void floydwarshall(int graph[][100], int N)
{
    int dist[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Shortest distance between every pair of vertices:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int N;
    printf("Enter the number of vertices: ");
    scanf("%d", &N);
    int graph[100][100];
    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    floydwarshall(graph, N);
    return 0;
}