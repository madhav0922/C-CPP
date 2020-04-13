#include<stdio.h>
int main()
    {
        int a,b,c,d,e;
        float avg;
        printf("Enter 5 numbers\n");
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        avg = (a+b+c+d+e)/(float)5;
        printf("%f\n",avg);
        return 0;
    }