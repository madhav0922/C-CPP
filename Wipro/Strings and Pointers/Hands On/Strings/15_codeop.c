#include<stdio.h>
#include<string.h>
int main()
{
    char *str[] = {"Welcome", "To", "Wipro", "Technologies", "Bangalore"};
    printf("lu, %lu \n", sizeof(str), strlen(str[0]));
    printf("%s \n", str[1]);
    printf("%c \n", str[2][2]);

}

/*
Output:
40, 7
To
p
*/