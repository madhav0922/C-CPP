#include<stdio.h>

int main()
{
    int *ptr, A[10], i;
    ptr = A;
    printf("Enter 10 numbers\n");
    for(i = 0 ; i < 10 ; i++)
        scanf("%d" , (ptr+i));
    for(i = 0 ; i < 10 ; i++)
        printf("%d ", *(ptr+(9-i)));
    printf("\n");
    return 0;
}