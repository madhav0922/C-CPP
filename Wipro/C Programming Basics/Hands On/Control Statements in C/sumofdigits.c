#include<stdio.h>
int main()
    {
        int m, n, sum=0, digit;
        printf("Input number is: ");
        scanf("%d",&n);
        m = n;
        
        while(n>0)
            {
                digit = n %10;
                n = n/10;
                sum += digit;
            }
        
        printf("The sum of the digits of %d is %d\n",m,sum);
    }