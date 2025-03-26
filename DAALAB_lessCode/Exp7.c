#include<stdio.h>
#define MAX 10
int n,m,w[MAX],x[MAX];
void printSolution(int k){
    printf("subset: ");
    for(int i=1;i<=k;i++){
        if(x[i]==1){
            printf("%d ",w[i]);
        }
    }
    printf("\n");
}
void sumofsubsets(int s,int i,int r){
    if(i>n) return;
    x[i]=1;
    if(s+w[i]==m){
        printSolution(i);
    }
    else if(s+w[i]+w[i+1]<=m){
        sumofsubsets(s+w[i],i+1,r-w[i]);
    }
    x[i]=0;
    if(s+w[i+1]<=m){
        sumofsubsets(s,i+1,r-w[i]);
    }
}
void main(){
    int total=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements in ascending order: ");
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        total+=w[i];
    }
    printf("Enter sum(M): ");
    scanf("%d",&m);
    printf("Subsets with sum %d: \n",m);
    sumofsubsets(0,1,total);
}
