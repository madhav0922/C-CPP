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

void mystrrev(char *str1, char *str2)
    {
        int i = 0;
        int  n = mystrlen(str1);
        
        for(i = 0 ; i < n ; i++)
            {
                str2[i] = str1[n-i-1];
            }
    }

int main()
    {
        char str1[20], str2[20];
        printf("Enter a string\n");
        fgets(str1, 20, stdin);

        printf("\nReversed string\n");
        mystrrev(str1, str2);
        puts(str2);
        return 0;
    }