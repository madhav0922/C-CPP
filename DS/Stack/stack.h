#include <stdio.h>
#include <stdlib.h>
static int Top = -1;
void push(char *S, int N, int x)
{
    if (Top == (N - 1))
        printf("\nStack full!!!\n");
    if (Top < N - 1)
        S[++Top] = x;
}

int pop(char *S, int N)
{
    if (Top == -1)
        printf("Stack empty\n");
    if (Top > -1)
        return (S[Top--]);
}

void peep(char *S, int i)
{
    //access the ith element from top of stack
    if ((Top - i + 1) > -1)
        printf("\n%d is the %dth element from top of stack\n", S[Top - i + 1], i);
}

void change(char *S, int i, int x)
{
    //change the ith element from top of stack
    if ((Top - i + 1) > -1)
        S[Top - i + 1] = x;
}
