#include<stdio.h>

int main()
{
        int arr[10]={2,3,4,5};
        int *ptr = arr;
        printf("%d\n",ptr[0]);

        ptr++;
        printf("%d\n",ptr[1]);
        printf("%d\n",ptr[2]);
}
/*
Output:
2
4
5
*/