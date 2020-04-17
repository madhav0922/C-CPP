#include<stdio.h>

int n = 20;
int main()
{
        int *ptr = &n;
        printf("%d\n", *ptr);
        (*ptr)++;
        printf("%d\n ", *ptr);
}

/*
Output:
20
21
*/