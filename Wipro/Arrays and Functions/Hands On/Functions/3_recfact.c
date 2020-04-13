#include<stdio.h>

int factorial(int n)
    {
        int fact = 1;
        if(n == 0 || n == 1)
            return 1;
        else
            {
                while(n > 1)
                {
                    fact = fact * n;
                    n--;
                }
            }
        return fact;
    }

int main()
    {
        int n;
        printf("Enter a positive integer: ");
        scanf("%d",&n);
        printf("Factorial of %d = %d\n",n,factorial(n));
        return 0;
    }