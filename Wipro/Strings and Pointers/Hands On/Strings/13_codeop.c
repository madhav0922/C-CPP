#include<stdio.h>

int main()
{
        char str[]="wipro";
        char *s=str;
        printf("%c \n", s[0]);
        printf("%c \n", s[1]);
        printf("%c \n", *(s + 3));
        return 0;
}

/*
Output: 
w 
i 
r
*/
