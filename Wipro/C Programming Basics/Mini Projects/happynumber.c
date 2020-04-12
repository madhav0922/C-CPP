#include<stdio.h>
#include<stdlib.h>

int is_happy_no(int n)
    {
        int r = 0, sum = 0;
        while(n>0)
            {
                r = n%10;
                sum = sum + (r*r);
                n = n/10;
            }
        return sum;
    }
int main(int argc, char** argv)
    {
        int result;
        result = atoi(argv[1]);
        while(result != 1 && result != 4)
            result  = is_happy_no(result);

        if(result == 1)
            printf("Happy number");    
    
        else if(result == 4)    
            printf("Unhappy number");    

        return 0; 
    }