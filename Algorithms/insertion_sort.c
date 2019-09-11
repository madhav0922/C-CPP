#include <stdio.h>
void insertion_sort_ite(int *A, int N)
{
    int i, j, key;
    for (j = 1; j < N; j++)
    {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}
// int insertion_sort_rec(int *A,int N)
// {
//     int j=1;
//     if(j>N)
//     {

//     }
// }
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
    insertion_sort_ite(a, n);
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