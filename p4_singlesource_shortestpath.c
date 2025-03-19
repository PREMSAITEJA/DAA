#include <stdio.h>
#define INF 99999

struct node
{
    int src, dest, weight;
};

void bellmanford(int vertices, int edges, struct node EdgeList[], int source)
{
    int dist[vertices];

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    for (int i = 1; i < vertices; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = EdgeList[j].src;
            int v = EdgeList[j].dest;
            int weight = EdgeList[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int j = 0; j < edges; j++)
    {
        int u = EdgeList[j].src;
        int v = EdgeList[j].dest;
        int weight = EdgeList[j].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            printf("Graph contains Negative weight cycle \n");
            return;
        }
    }

    printf("Minimum distance from source vertex %d: \n", source);
    for (int i = 0; i < vertices; i++)
    {
        printf("%d \t %d\n", i, (dist[i] == INF) ? -1 : dist[i]);
    }
}

int main()
{
    int vertices, source, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &vertices, &edges);

    struct node EdgeList[edges];

    printf("Enter the edges (source, destination, weight): \n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d%d%d", &EdgeList[i].src, &EdgeList[i].dest, &EdgeList[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanford(vertices, edges, EdgeList, source);

    return 0;
}