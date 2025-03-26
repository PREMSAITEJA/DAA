#include<stdio.h>
#define INF 99999
void floydWarshall(int graph[][100],int n){
    int dist[100][100];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dist[i][j]=graph[i][j];
    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(dist[i][k]!=INF && dist[k][j]!=INF && (dist[i][k]+dist[k][j]<dist[i][j])){
        dist[i][j]=dist[i][k]+dist[k][j];
    }
    printf("Shortest distance between every pair of vertices: \n");
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(dist[i][j]==INF)
        printf("INF ");
    else
        printf("%d ",dist[i][j]);
    }
    printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int graph[100][100];
    printf("Enter the adjacency matric(use %d for INF): \n",INF);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
            scanf("%d",&graph[i][j]);
        }
    }
    floydWarshall(graph,n);
    return 0;
}
