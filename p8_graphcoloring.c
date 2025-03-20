#include <stdio.h>
#define MAX 10

int n, m;        
int G[MAX][MAX];  
int x[MAX];           
void printSolution()
{
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void NextValue(int k)
{
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)               
            return;

        int valid = 1;
        for (int j = 1; j <= n; j++)
        {
            if (G[k][j] == 1 && x[k] == x[j])
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            return;
    }
}

void mcoloring(int k)
{
    while (1)
    {
        NextValue(k); 
        if (x[k] == 0) 
            return;

        if (k == n)
            printSolution();
        else
            mcoloring(k + 1);
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    printf("Possible Colorings:\n");
    mcoloring(1); 

    return 0;
}