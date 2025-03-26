#include<stdio.h>
void findMaxMin(int a[],int l,int h,int *max,int *min)
{
    int mid,min1,max1,max2,min2;
    if(l==h){
        *min=a[l];
        *max=a[l];
        return;
    }
    else if(l==h-1)
    {
        if(a[l]>a[h])
        {
            *max=a[l];
            *min=a[h];
        }
        else{
            *max=a[h];
            *min=a[l];
        }
    }
    else{
    mid=(l+h)/2;
    findMaxMin(a,l,mid,&max2,&min2);
    findMaxMin(a,mid+1,h,&max1,&min1);
    *max = (max2 > max1) ? max2 : max1;
    *min = (min2 < min1) ? min2 : min1;
    return;
    }
}
void main(){
    int a[100],n,i,max=0,min=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    findMaxMin(a,0,n-1,&max,&min);
    printf("Max: %d\nMin: %d",max,min);
}
