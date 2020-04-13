#include<stdio.h>
#include<math.h>
int primenum(int n)
    {
        int i,flag=1;
        for(i=2;i<= sqrt(n);i++)  
        {
            if(n%i == 0)
                return flag-1; 
        }
        return flag;
    }

int main()
    {
        int start = 2, range, first, second, n;

        printf("Enter a positive integer: ");
        scanf("%d",&n);

        for(range = n-start; range >= start; range--)
            {
                if(primenum(start) && primenum(range))
                    {
                        printf("%d  = %d + %d\n",n,start,range);
                    }
                start++;
            }
        return 0;
    }