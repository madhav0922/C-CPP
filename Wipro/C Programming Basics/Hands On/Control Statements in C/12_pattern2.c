#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv)
    {
        int i,j,k,temp,n;
        n = atoi(argv[1]);
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
                        printf("%s",argv[2]);
                        temp--;
                    }
                j++;

                printf("\n");
            }
        return 0;
    }
