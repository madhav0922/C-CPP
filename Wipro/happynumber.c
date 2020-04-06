#include<stdio.h>

happy(int n)
    {
        int dig1,dig2,digit = n;
        while(digit % 0 != 1)
            {
                if(sq > 10)
                    {
                        dig1 = sq%10;
                        dig2 = sq/10;
                        sq = (dig1 * dig1) + (dig2 * dig2);
                    }
                else
                    sq = digit * digit;
                
            }
    }
int main(int argc, char *argv[])
    {
        if( argc == 2 ) {
            printf("The argument supplied is %s\n", argv[1]);
        }
        else if( argc > 2 ) {
            printf("Too many arguments supplied.\n");
        }
        else {
            printf("One argument expected.\n");
        }

        happy(argv[1]);
    }