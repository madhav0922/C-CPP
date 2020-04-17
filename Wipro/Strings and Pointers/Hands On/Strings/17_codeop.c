#include<stdio.h>

int main()
{
        char *s[]={"DELHI","PUNE","GOA","KOCHI"};
        char *p;
        p=s[1];
        printf("%c\n",*p);

        p++;
        printf("%c\n",*p);
        printf("%c\n",*(p + 2));
}

/*
Output:
P
U
E
*/