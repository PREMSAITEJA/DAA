#include<stdio.h>
#define MAX 10
int n,m,G[MAX][MAX],x[MAX];
void printSolution(){
    for(int i=1;i<=n;i++)
    printf("%d ",x[i]);
    printf("\n");
}
void nextValue(int k){
    while(1){
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)return;
        int j;
        for(j=1;j<k;j++){
            if(G[j][k]==1 && x[j]==x[k])
                break;
        }
        if(j==k) return;
    }
}
void mcoloring(int k){
    while(1){
        nextValue(k);
        if(x[k]==0)return;
        if(k==n){
            printSolution();
        }
        else{
            mcoloring(k+1);
        }
    }
}
int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of colors: ");
    scanf("%d",&m);
    printf("Enter adjacency matrix: ");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("Possible Colourings : \n");
    mcoloring(1);
    return 0;
}
