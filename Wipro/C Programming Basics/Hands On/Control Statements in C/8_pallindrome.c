#include<stdio.h>
int main()
    {
        int m,n,rev=0,digit;
        printf("Enter the number: ");
        scanf("%d",&n);
        m = n;
        
        while(n>0)
            {
                digit = n %10;
                n = n/10;
                rev = rev * 10 + digit;
            }
        
        if(m == rev)
            printf("%d is a pallindrome\n",m);
        else
            printf("%d is not a pallindrome\n",m);
        return 0;
    }