#include<stdio.h>
void main()
{
    int m,n,i,j,w[10],p[10],x[10],t;
    float r[10],tp=0.0;
    printf("Enter the capacity : ");
    scanf("%d",&m);
    printf("Enter no.of items : ");
    scanf("%d",&n);
    printf("Enter the weight and profit of the item : ");
    for(i=0;i<n;i++){
        scanf("%d%d",&w[i],&p[i]);
        r[i]=(float)p[i]/w[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            t=r[j];
            r[j]=r[i];
            r[i]=t;
            t=w[i];
            w[i]=w[j];
            w[j]=t;
            t=p[i];
            p[i]=p[j];
            p[j]=t;
        }
    }
    for(i=0;i<n;i++){
        if(w[i]<m){
            tp+=(float)p[i];
            m-=p[i];
        }
        else{
            tp+=(float)p[i]/w[i];
        }
    }
    printf("Total Optimal profit : %f\n",tp);
}
