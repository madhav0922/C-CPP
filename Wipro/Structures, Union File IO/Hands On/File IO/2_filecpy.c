#include<stdio.h>

int main()
{
    //printf("%s%s",argv[1],argv[2]);
    char ch;
    FILE *source, *target;
    
    source = fopen("abc","r");
    target = fopen("def","w");

    ch = getc(source);
    while(ch != EOF)
        {
            putc(ch, target);
            ch = getc(source);
        }

    fclose(source);
    fclose(target);
    printf("Content in file \n");

    target = fopen("def","r");
    ch = getc(target);
    while(ch != EOF)
        {
            putchar(ch);
            ch = getc(target);
        }

    fclose(target);
    printf("\n");
    return 0;
}
