#include <stdio.h>
#include <stdlib.h>
static int Top = -1;
void push(int *S, int N, int x)
{
    if (Top == (N - 1))
        printf("\nStack is full!!!\n");
    if (Top < N - 1)
        S[++Top] = x;
}

void pop(int *S, int N)
{
    if (Top == -1)
        printf("Stack empty\n");
    if (Top > -1)
        printf("\n%d popped from stack\n", S[Top--]);
}

void peep(int *S, int i)
{
    //access the ith element from top of stack
    if ((Top - i + 1) > -1)
        printf("\n%d is the %dth element from top of stack\n", S[Top - i + 1], i);
}

void change(int *S, int i, int x)
{
    //change the ith element from top of stack
    if ((Top - i + 1) > -1)
        S[Top - i + 1] = x;
}

int main()
{
    int N, S[10], ch, x, i, k;
    printf("\nEnter size of stack ");
    scanf("%d", &N);
l1:
    printf("\n\nSELECT\n1.Push into Stack\n2.Pop from Stack\n3.Peep\n4.Change\n5.Exit\n\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter element to push in stack ");
        scanf("%d", &x);
        push(S, N, x);
        break;
    case 2:
        pop(S, N);
        break;
    case 3:
        printf("\nEnter position you want to peep from top of stack ");
        scanf("%d", &i);
        peep(S, i);
        break;
    case 4:
        printf("\nEnter position from top of stack at which you want to change the value ");
        scanf("%d", &i);
        printf("\nEnter new value ");
        scanf("%d", &x);
        change(S, i, x);
        break;
    case 5:
        printf("Terminated\n");
        exit(0);
    }

    printf("\nElements in Stack: ");
    for (k = Top; k > -1; k--)
        printf("%d ", S[k]);
    goto l1;
}
