#include <stdio.h>

int binary_search(int *A, int low, int high, int k)
{
    int mid;

    if (low > high)
        return -1;
    else
    {
        mid = low + (high - low) / 2;

        if (A[mid] == k)
            return mid;

        if (A[low] < A[mid])
        {
            if (A[low] <= k && k < A[mid])
                return binary_search(A, low, mid - 1, k);
            else
                return binary_search(A, mid + 1, high, k);
        }

        else
        {
            if (k > A[mid] && k <= A[high])
                return binary_search(A, mid + 1, high, k);
            else
                return binary_search(A, low, mid - 1, k);
        }
    }
}
int main()
{
    int a[8] = {5, 9, 10, 12, 15, 1, 3, 4}, low = 0, mid, high = 7, k, index;
    k = 1;
    printf("Element Found at position %d", binary_search(a, low, high, k));
}