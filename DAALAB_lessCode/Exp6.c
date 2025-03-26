#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int x[100];
int place(int k,int i)
{
    for(int j=1;j<k;j++){
        if((x[j]==i) || abs(x[j]-i)==abs(j-k)){
        return 0;
        }
    }
    return 1;
}
void Nqueens(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
            for(int i=1;i<=n;i++){
            printf("%d ",x[i]);
            }
            printf("\n");
            }
            else
                Nqueens(k+1,n);
        }
    }
}
void main()
{
    int n;
    printf("Enter the size of the square: ");
    scanf("%d",&n);
    Nqueens(1,n);
}
