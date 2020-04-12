#include<stdio.h>
int main()
    {
        int n,rev=0,digit;
        printf("Enter the number to reverse: ");
        scanf("%d",&n);
        while(n>0)
            {
                digit = n %10;
                n = n/10;
                rev = rev * 10 + digit;
            }
        printf("Reverse of entered number is %d\n",rev);
    }