#include<stdio.h>

int main()
    {
        int i,j,k,temp,n;
        printf("How many rows are to be printed: ");
        scanf("%d",&n);
        j=1;
        for(i = 1; i <= (2*n)-1; i=i+2)
            {
                //print spaces
                for(k = n-1 ; k >= j; k--)
                    printf(" ");
                
                //print pattern
                temp = i;
                while(temp>0)
                    {
                        printf("*");
                        temp--;
                    }
                j++;

                printf("\n");
            }
        return 0;
    }
