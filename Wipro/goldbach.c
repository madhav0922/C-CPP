#include<stdio.h>
#include<math.h>

int isprime(int n)
    {
        int i,flag=1;
        for(i=2;i<= sqrt(n);i++)  
        {
            if(n%i == 0)
                return flag-1; 
        }
        return flag;
    }
void goldbach(int n)
    {
        int start = 2, range, first, second;

        for(range = n-start; range >= start; range--)
            {
                if(isprime(start) && isprime(range))
                    {
                        first = start; 
                        second = range;
                    }
                start++;
            }
        printf("%d %d %d\n",n,first,second);
    }

int main()
    {
        int n[10],i,j=0;
        for(i=0;i<5;i++)
            scanf("%d",&n[i]);
        
        while(j<5)
        {   
            if(n[j]>=4 && n[j]%2==0)
                goldbach(n[j]);
            else
                printf("Wrong choice");
            j++;
        }
        return 0;
    }