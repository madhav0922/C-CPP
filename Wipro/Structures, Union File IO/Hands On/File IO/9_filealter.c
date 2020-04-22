#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 512

int main(int argc, char** argv)
{
    char ch;
    FILE *source1, *source2, *target;
    char line1[MAX], line2[MAX], target_file[] = "temp.txt";
    source1 = fopen(argv[1], "r");
    source2 = fopen(argv[2], "r");
    target = fopen(target_file,"w");

    while((!feof(source1)) || (!feof(source2)))
    {
        fgets(line1, MAX, source1);
        if(!feof(source1))
            fprintf(target, "%s", line1);
        
        fgets(line2, MAX, source2);
        if(!feof(source2))
            fprintf(target, "%s", line2);
        
        strcpy(line1, "\0");
        strcpy(line2, "\0");
    }

    fclose(source1);
    fclose(source2);
    fclose(target);

    target = fopen(target_file,"r");
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
