#include<stdio.h>

int main()
{
        int a = 40;
        int *x = &a;
        int **y = &x;
        printf("%d%d%d\n", a, *x, **y);
}

/*
Output:
404040
*/