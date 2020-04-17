#include<stdio.h>

int main()
{
    int *ptr, A[10], B[10], temp, i, j;
    ptr = A;
    printf("Enter marks of 10 students\n");
    for(i = 0 ; i < 10 ; i++)
        scanf("%d",(ptr+i));
    
    for(i = 0 ; i < 10 ; i++)
        {
            for(j = i+1 ; j < 10 ; j++)
                {
                    if(*(ptr + i) > *(ptr + j))
                        {
                            temp = *(ptr + i);
                            *(ptr + i) = *(ptr + j);
                            *(ptr + j) = temp;
                        }
                }
        }
    for(i = 0 ; i < 10 ; i++)
        *(B + i) = *(ptr + i);

    for(i = 0 ; i < 10 ; i++)
        printf("%d ", *(B + i));
    
    printf("\n");
    return 0;
}