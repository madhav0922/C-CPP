#include <stdio.h>
#include <string.h>
#include "stack.h"
prefix_eval(char *S, int N)
{
    int A[20], i, left_operand, right_operand, temp;
    char operator;
    for (i = N - 1; i > -1; i--)
    {
        if (isdigit(S[i]))
            push(A, N, S[i]);
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/' || S[i] == '%')
        {
            operator= S[i];
            left_operand = pop(S, N);
            right_operand = pop(S, N);
            temp = left_operand operator right_operand;
            push(A, N, temp);
        }
    }
}

int main()
{
    int ch, N, x, i;
    char S[20];
    printf("Enter size of expression\n");
    scanf("%d", &N);
    printf("\n1.Prefix Evaluation\n2.Postfix Evaluation\n3.Infix Evaluation\n");
    switch (ch)
    {
    case 1:
        printf("Enter prefix expression\n");
        for (i = 0; i < N; i++)
            push(S, N, x);
        break;
    case 2:
        printf("Enter postfix expression\n");
        for (i = 0; i < N; i++)
            push(S, N, x);
        break;
    case 3:
        printf("Enter infix expression\n");
        for (i = 0; i < N; i++)
            push(S, N, x);
        break;
    }
}