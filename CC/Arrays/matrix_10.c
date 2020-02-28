#include <stdio.h>
void print(int m, int n, int A[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void matrix_sum(int m, int n, int A[m][n])
{
    //with extra space complexity and T(n) = O(m+n)
    int R[m], C[n], i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                R[i] = 1;
                C[j] = 1;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (R[i] == 1 || C[j] == 1)
                A[i][j] = 1;
        }
    }
}

void matrix_sum_1(int m, int n, int A[m][n])
{
    //T(n) = O(1) and no extra space
    int i, j, r_flag = 0, c_flag = 0;
    for (i = 0; i < m; i++)
    {
        //for all rows in first column
        if (A[i][0] == 1)
            r_flag = 1;
    }
    
    for (j = 0; j < n; j++)
    {
        //for all columns in first row
        if (A[0][j] == 1)
            c_flag = 1;
    }
    
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                A[i][0] = A[0][j] = 1;
            }
        }
    }

    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (A[0][i] == 1 || A[j][0] == 1)
                A[i][j] = 1;
        }
    }
    for (i = 0; i < m; i++)
    {
        if (r_flag == 1)
            A[i][0] = 1;
    }
    
    for (j = 0; j < n; j++)
    {
        if (c_flag == 1)
            A[0][j] = 1;
    }
    
}

int main()
{
    int A[2][3] = {{1, 0, 0}, {0, 0, 0}};
    int m = 2, n = 3;
    matrix_sum_1(m, n, A);
    print(m, n, A);
}