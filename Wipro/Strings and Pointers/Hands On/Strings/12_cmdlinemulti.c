#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv)
    {   
        if(argc < 5 || argc > 5)
            printf("Invalid number of Parameters. Please try again\n");
        else
        {
            printf("%d %d %d %s\n",atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),argv[4]);
        }
        return 0;
    }