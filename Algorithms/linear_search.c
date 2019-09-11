#include <stdio.h>
int linear_search_ite(int *A, int N, int ele)
{
    int i, flag = 0, index;
    for (i = 0; i < N; i++)
        if (A[i] == ele)
            return i; //print key and print index with i;
    return -1;
}
int linear_search_rec(int *A, int N, int ele)
{
    if (N < 0)
        return -1;
    else if (A[N] == ele)
        return N;
    return linear_search_rec(A, N - 1, ele);
}
int main()
{
    int n, a[10], i, k, x, flag = -1, ele, temp;
    printf("Enter size of array\n");
    scanf("%d", &n);
    printf("Enter elements into array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search\n");
    scanf("%d", &ele);
    printf("Choose from following:\n");
    printf("1. Execute using iterative code\n");
    printf("2. Execute using recursive code\n\n");
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        flag = linear_search_ite(a, n, ele);
        break;
    case 2:
        flag = linear_search_rec(a, n - 1, ele);
        break;
    }
    printf("flag %d", flag);
    if (flag == -1)
        printf("\nElement not found\n");
    else
        printf("\nElement %d found at index %d\n", ele, flag);
}
