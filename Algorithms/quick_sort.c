#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *A, int low, int high)
{
    int p, i, j;
    p = A[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (A[j] < p)
        {
            i = i + 1;
            if (i != j)
                swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}
void quicksort(int *A, int low, int high)
{
    if (low < high)
    {
        int K = partition(A, low, high);
        quicksort(A, low, K - 1);
        quicksort(A, K + 1, high);
    }
}

int main(void)
{

    int a[10] = {1, 5, 8, 12, 3, 9, 4, 7, 10, 20}, i, low, high;
    low = 0;
    high = 9;
    printf("\nSorted array\n");
    quicksort(a, low, high);
    for (i = low; i < high; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
