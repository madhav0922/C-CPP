#include <stdio.h>

void merge(int *A, int low, int mid, int high)
{
    int p = mid - low + 1;
    int q = high - mid;
    int L[p + 1], R[q + 1], i, j, k;
    for (i = low; i < p; i++)
        L[i] = A[low + i];
    for (j = 1; j < q; j++)
        R[j] = A[mid + j];
    i = j = 0;
    // L[p + 1] = __INT_MAX__;
    // R[q + 1] = __INT_MAX__;
    for (k = low; k < high; k++)
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
}
int merge_sort(int *A, int low, int high)
{
    if (low == high)
        return (A[low]);
    else
    {
        int mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
    return -1;
}
int main(void)
{

    int a[10] = {1, 5, 8, 12, 3, 9, 4, 7, 10, 20}, i, low, high;
    low = 0;
    high = 9;
    printf("\nSorted array\n");
    merge_sort(a, low, high);
    for (i = low; i < high; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
