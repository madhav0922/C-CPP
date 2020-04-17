#include<stdio.h>

void swap(int *a ,int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

int main()
    {
        int x, y;
        printf("Enter two numbers\n");
        scanf("%d%d",&x,&y);

        printf("Before swapping: a = %d b = %d\n", x, y);
        swap(&x,&y);
        printf("After Swapping: a = %d b = %d\n", x, y);
    }