#include<stdio.h>

int main()
{
        int list[5]={4,3,6,8,9};
        int *ptr;
        ptr=&list[1];
        printf("%d %d\n",*ptr,ptr[0]);
         printf("%d %d\n",*(ptr + 1),*(ptr + 2));
}

/*
Output:
3 3
6 8
*/