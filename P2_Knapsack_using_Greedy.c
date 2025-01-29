#include<stdio.h>
void main(){
    int m,n,i,j,w[10],p[10],temp,x[10];
    float r[10], tp = 0.0;
    printf("Enter the capacity: ");
    scanf("%d",&m);
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter Weights and Profits of items: ");
    for(i=0;i<n;i++){
        scanf("%d %d",&w[i],&p[i]);
        r[i]=(float)p[i]/w[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(r[i]<r[j]){
                temp=r[i];
                r[i]=r[j];
                r[j]=temp;
                temp=w[i];
                w[i]=w[j];
                w[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for (i = 0; i < n;i++){
        if(w[i]<m){
            tp+=(float)p[i];
            m -=p[i];
        }
        else{
            tp += (float)p[i] / w[i];
        }
    }
    printf("Total Optimal profit : %f\n", tp);
}