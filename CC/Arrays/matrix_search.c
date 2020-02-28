#include <stdio.h>
static int i;
int matrix_n2(int A[][4], int ele)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (A[i][j] == ele)
                return 1;
    }
    return 0;
}

int binary_search(int A[i][4], int l, int r, int ele)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (A[mid][i] == ele)
            return 1;

        if (A[mid][i] > ele)
            return binary_search(A, l, mid - 1, ele);

        return binary_search(A, mid + 1, r, ele);
    }

    return -1;
}

int matrix_nlogn(int A[][4], int ele)
{
    int low = 0, mid, high = 4, f, j;
    for (j = 0; j < 4; j++)
    {
        f = binary_search(A, low, high - 1, ele);
        if (f == 1)
            return f;
        i++;
    }
    return f;
}

void matrix_n(int A[4][4], int ele)
{
    int m = 0, n = 4, i, j;
    while (i < m && j >= 0)
    {
    }
}
int main()
{
    int A[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}}, f = 0;
    //f = matrix_n2(A, 29);
    //f = matrix_n2(A, 8);
    //f = matrix_n2(A, 32);
    f = matrix_nlogn(A, 29);
    if (f == 1)
        printf("Found\n");
    else
        printf("Not found\n");
}