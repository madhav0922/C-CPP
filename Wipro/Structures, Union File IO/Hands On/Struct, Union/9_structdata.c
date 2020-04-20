#include<stdio.h>
#include<stdlib.h>

struct data
{
 int num1; 
 int num2; 
 int num3;
 int average; 
 
}; 

void calaverage(struct data *x)
{
    x -> average = (x -> num1 + x -> num2 + x -> num3) / 3 ;
}

int main()
{
    struct data *dptr;

    dptr = (struct data*) malloc (sizeof(struct data));

    printf("Enter 3 numbers\n");
    scanf("%d%d%d", &dptr -> num1, &dptr -> num2, &dptr -> num3);
    calaverage(dptr);
    printf("Average: %d\n", dptr -> average);
    return 0;
}