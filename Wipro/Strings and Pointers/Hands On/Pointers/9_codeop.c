#include<stdio.h>

int main()
{
    int list[3],*i;
    list[0]=10;
    list[1]=20;
    list[2]=30;
    i=list;
    printf("%d ", ++*i);
    printf("%d ", *++i);
    printf("%d ", (*i)--);
    printf("%d", *i);
}

/*
Output:
11 20 20 19
*/