#include<stdio.h>

int mystrlen(char *str)
    {
        int i = 0, count = 0;
        while(str[i] != '\0')
            {
                count++;
                i++;
            }
        return count;
    }

int main(int argc, char** argv)
{
    printf("%d\n",mystrlen(argv[1]));
    return 0;
}