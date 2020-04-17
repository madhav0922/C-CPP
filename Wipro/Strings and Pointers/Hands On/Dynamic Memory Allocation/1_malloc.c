#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    ptr = (int*)malloc(1 * sizeof(int));
    if(ptr == NULL)
        printf("Memory couldn't be allocated.\n");
    else
        {
            printf("Enter a number\n");
            scanf("%d",ptr);
            printf("Entered number is: %d\n",*ptr);
        }
    return 0;
}