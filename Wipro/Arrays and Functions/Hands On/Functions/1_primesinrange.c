#include<stdio.h>
#include<math.h>
int checkPrime(int n)
    {
        int i, flag = 1;
        for(i=2;i<= sqrt(n);i++)  
        {
            if(n%i == 0)
                return flag-1; 
        }
        return flag;
    }

int main()
    {
        int a,b;
        printf("Enter two positive integers\n");
        scanf("%d%d",&a,&b);
        for(int i = a ; i <= b ; i++)
                if(checkPrime(i))
                    printf("%d ",i);
        return 0;
    }