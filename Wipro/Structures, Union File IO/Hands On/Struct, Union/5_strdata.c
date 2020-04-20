#include<stdio.h>

struct data
{
 int num1; 
 int num2; 
 int num3;
 int average; 
 
}; 

struct data calaverage(struct data x)
{
    x.average = (x.num1 + x.num2 + x.num3) / 3 ;
    return x;
}

int main()
{
    struct data d1, x;
    printf("Enter 3 numbers\n");
    scanf("%d%d%d", &d1.num1, &d1.num2, &d1.num3);
    x = calaverage(d1);
    printf("Average: %d\n", x.average);
    return 0;
}