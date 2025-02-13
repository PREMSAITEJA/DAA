#include <stdio.h>
#include <stdlib.h>
typedef struct File
{
    int size;
} File;
void swap(File *a, File *b)
{
    File temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(File files[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && files[left].size < files[smallest].size)
    {
        smallest = left;
    }
    if (right < n && files[right].size < files[smallest].size)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&files[i], &files[smallest]);
        heapify(files, n, smallest);
    }
}
void buildMinHeap(File files[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(files, n, i);
    }
}
File extractMin(File files[], int *n)
{
    File minFile = files[0];
    files[0] = files[*n - 1];
    (*n)--;
    heapify(files, *n, 0);
    return minFile;
}
void insertHeap(File files[], int *n, File newFile)
{
    (*n)++;
    int i = *n - 1;
    files[i] = newFile;
    while (i != 0 && files[(i - 1) / 2].size > files[i].size)
    {
        swap(&files[i], &files[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int calculateOptimalMergeCost(File files[], int n)
{
    int totalCost = 0;
    buildMinHeap(files, n);
    while (n > 1)
    {
        File file1 = extractMin(files, &n);
        File file2 = extractMin(files, &n);
        int mergeCost = file1.size + file2.size;
        totalCost += mergeCost;
        File mergedFile;
        mergedFile.size = mergeCost;
        insertHeap(files, &n, mergedFile);
    }
    return totalCost;
}
void printFileSizes(File files[], int n)
{
    printf("File sizes: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", files[i].size);
    }
    printf("\n");
}
void initializeFiles(File files[], int sizes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        files[i].size = sizes[i];
    }
}
void main()
{
    int n, i;
    printf("Enter no of files : ");
    scanf("%d", &n);
    int sizes[n];
    printf("Enter sizes of files :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &sizes[i]);
    }
    File *files = (File *)malloc(n * sizeof(File));
    initializeFiles(files, sizes, n);
    printf("Before merging:\n");
    printFileSizes(files, n);
    int totalCost = calculateOptimalMergeCost(files, n);
    printf("Optimal merge cost: %d\n", totalCost);
    free(files);
}