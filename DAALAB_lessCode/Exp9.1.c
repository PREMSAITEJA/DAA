#include <stdio.h>
#define MAX 20  
int graph[MAX][MAX], path[MAX], n, cycleFound = 0;  

int isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v]) return 0;  
    for (int i = 0; i < pos; i++)      
        if (path[i] == v) return 0;  
    return 1;
}
void findHamiltonian(int pos) {
    if (pos == n) {  
        if (graph[path[pos - 1]][path[0]]) {  
            for (int i = 0; i < n; i++) printf("%d ", path[i]);
            printf("%d\n", path[0]);  
            cycleFound = 1;  
        }
        return;
    }
    for (int v = 1; v < n; v++) {  
        if (isSafe(v, pos)) {
            path[pos] = v;
            findHamiltonian(pos + 1);
            path[pos] = -1;  
        }
    }
}
int main() {
    printf("Nodes: ");
    scanf("%d", &n);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) path[i] = -1;  
    path[0] = 0; 
    printf("Hamiltonian Cycles:\n");
    findHamiltonian(1);
    if (!cycleFound)  
        printf("No Hamiltonian Cycle found.\n");

    return 0;
}
