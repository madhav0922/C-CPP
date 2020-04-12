#include<stdio.h>
#include<math.h>
int main()
    {
        int n , flag=0;
        printf("Enter a number: ");
        scanf("%d",&n);
        if(n == 0 || n == 1)
            {
                printf("%d is neither prime nor composite\n",n);
                return 0;
            }
        for(int i = 2 ; i <= sqrt(n) ; i++)
            if(n%i == 0)
                {
                    flag = 1;
                    break;
                }
        if(flag == 1)
            printf("%d is not a prime number\n",n);
        else
            printf("%d is a prime number\n",n);
        return 0;
    }