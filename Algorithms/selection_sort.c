#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x; //not *temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort_ite(int *A, int N)
{
    int i, j, min_value, min, temp;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        swap(&A[i], &A[min]);
    }
}
int main()
{
    int i, n, x, a[10];
    printf("Enter size of array\n");
    scanf("%d", &n);
    printf("Enter elements into array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // printf("Choose from following:\n");
    // printf("1. Execute using iterative code\n");
    // printf("2. Execute using recursive code\n\n");
    //scanf("%d", &x);

    // switch (x)
    // {
    // case 1:
    selection_sort_ite(a, n);
    //    break;
    // case 2:
    //     insertion_sort_rec(a, n);
    //     break;
    //}
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}