#include<stdio.h>
#include<stdlib.h>
#define INF 99999
typedef struct node{
   int src,dest,weight
};
void bellmanFord(int vertices,int edges,struct node EdgeList[],int source){
    int dist[vertices];
    for(int i=0;i<vertices;i++)
        dist[i]=INF;
    dist[source]=0;
    for(int i=1;i<vertices;i++){
        for(int j=1;j<edges;j++){
            int u=EdgeList[j].src;
            int v=EdgeList[j].dest;
            int weight=EdgeList[j].weight;
            if(dist[u]!=INF && dist[u]+weight < dist[v]){
                dist[v]=dist[u]+weight;
            }
        }
    }
    for(int j=0;j<edges;j++){
          int u=EdgeList[j].src;
            int v=EdgeList[j].dest;
            int weight=EdgeList[j].weight;
            if(dist[u]!=INF && dist[u]+weight < dist[v])
                printf("Graph contain Negative weight cycle.\n");
    }
    printf("Minimum distance from source vertex: ");
    for(int i=1;i<=vertices;i++)
        printf("%d\t\t%d\n",i,(dist[i]==INF)?-1:dist[i]);
}
void main(){
    int vertices,source,edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d",&vertices,&edges);
    struct node EdgeList[edges];
    printf("Enter the edges(source,dest,weight): ");
    for(int i=0;i<edges;i++)
        scanf("%d%d%d",&EdgeList[i].src,&EdgeList[i].dest,&EdgeList[i].weight);
    printf("Enter source vertex: ");
    scanf("%d",&source);
    bellmanFord(vertices,edges,EdgeList,source);
}

