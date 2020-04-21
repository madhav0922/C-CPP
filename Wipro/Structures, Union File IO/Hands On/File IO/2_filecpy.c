#include<stdio.h>

int main(int argc, char** argv)
{
    char ch;
    FILE *source, *target;
    
    source = fopen(argv[1],"r");
    target = fopen(argv[2],"w");

    ch = getc(source);
    while(ch != EOF)
        {
            putc(ch, target);
            ch = getc(source);
        }

    printf("File copied successfully!\n");

    fclose(source);
    fclose(target);
    printf("Content in file %s\n",argv[2]);

    target = fopen(argv[2],"r");
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
