#include<stdio.h>

int main()
{

    char *ptr="uvwxyzabc";
    printf("%c \n",2[ptr]);
    printf("%c \n",ptr[2]);
    printf("%c \n",*(ptr + 2));

}

/*
Output:
w
w
w
*/