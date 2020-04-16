#include<stdio.h>

int mystrlen(char *str)
    {
        int i = 0, count = -1;
        while(str[i] != '\0')
            {
                count++;
                i++;
            }
        return count;
    }

int main()
    {
        char str[20];
        printf("Enter a string\n");
        fgets(str, 20, stdin);
        printf("\n%d\n", mystrlen(str));
        return 0;
    }