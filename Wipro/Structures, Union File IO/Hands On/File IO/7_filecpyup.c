#include<stdio.h>
#include<ctype.h>

int main(int argc, char** argv)
{
    char ch;
    FILE *source, *target;
    
    source = fopen(argv[1],"r");
    target = fopen("output.txt","a");

    ch = getc(source);
    while(ch != EOF)
        {
            putc(toupper(ch), target);
            ch = getc(source);
        }

    fclose(source);
    fclose(target);

    target = fopen("output.txt","r");
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
