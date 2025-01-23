#include <stdio.h>
#include <limits.h>

int max = INT_MIN, min = INT_MAX;
int memo_max[100], memo_min[100];

void min_max(int a[], int l, int r)
{
    if (l == r)
    {
        max = min = a[l];
    }
    else if (l == (r - 1))
    {
        if (a[l] > a[r])
        {
            max = a[l];
            min = a[r];
        }
        else
        {
            max = a[r];
            min = a[l];
        }
    }
    else
    {
        int mid = (l + r) / 2;
        min_max(a, l, mid);
        int max1 = max, min1 = min;
        min_max(a, mid + 1, r);
        if (max1 > max)
        {
            max = max1;
        }
        if (min1 < min)
        {
            min = min1;
        }
    }
    memo_max[l] = max;
    memo_min[l] = min;
}

void main()
{
    int n;
    int a[100];
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter the array elements value less than 1000: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    min_max(a, 0, n - 1);
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);
}