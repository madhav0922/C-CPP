#include<stdio.h>
int main()
    {
        int a,b,GREATER;
        printf("Enter two numbers\n");
        scanf("%d%d",&a,&b);
        GREATER = (a>b)?a:b;
        printf("%d\n",GREATER);
        return 0;
    }