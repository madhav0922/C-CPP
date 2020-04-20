#include<stdio.h>

struct smemo {
 int nVal;
 char cVal;
};

union umemo {
 int nVal;
 char cVal;
};

void get_structdata(struct smemo *s)
{
    printf("Enter data in structure:\n");
    printf("Enter a number\n");
    scanf("%d", &s -> nVal);
    getchar();
    printf("Enter a character\n");
    scanf("%c",&s -> cVal);
}

void get_uniondata(union umemo u)
{
    printf("Enter data in union:\n");
    printf("Enter a number\n");
    scanf("%d", &u.nVal);
    getchar();
    printf("Enter a character");
    scanf("%c",&u.cVal);
}

void print_struct(struct smemo *s)
{
    printf("Num: %d\n",s -> nVal);
    printf("Char: %c\n",s -> cVal);
}

void print_union(union umemo u)
{
    printf("Num: %d\n",u.nVal);
    printf("Char: %c\n",u.cVal);
}

int main()
{
    struct smemo *s;
    union umemo u;
    
    get_structdata(s);
    get_uniondata(u);
    
    printf("Structure:\n");
    print_struct(s);

    printf("Union:\n");
    print_union(u);

    printf("\nSize of union %lu bytes\n",sizeof(u));

    return 0;
}