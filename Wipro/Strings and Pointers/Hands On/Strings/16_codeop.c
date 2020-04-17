#include<stdio.h>
#include<string.h>
int main()
{
        char str1[] = "HelloWipro";
        char str2[20];
        char *t, *s;

        memset(str2, 0, sizeof(str2));
        s = str1;
        t = str2;

        while(*s)
                *t++ = *s++;

        printf("%s\n", str2);
        return 0;
}

/*
Output:
HelloWipro
*/