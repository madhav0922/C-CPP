#include <stdio.h>
int max_element(int *A, int N)
{
    int i, curr_max;
    curr_max = A[1];
    for (i = 2; i < N; i++)
        if (A[i] > curr_max)
            curr_max = A[i];
    return curr_max;
}
int main()
{
    int k, n = 5, A[] = {5, 0, 8, 3, 7};
    k = max_element(A, n);
    printf("%d", k);
}