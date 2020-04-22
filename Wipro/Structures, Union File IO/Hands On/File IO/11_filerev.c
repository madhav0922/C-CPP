#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

void mystrrev(char *str1, char *str2)
    {
        int i = 0, n = 0;
        while(str1[i++])
            n++;
        
        for(i = 0 ; i < n ; i++)
            {
                str2[i] = str1[n-i-1];
            }
    }

int main(int argc, char** argv)
{
    FILE *source, *target;
    char ch, rev[MAX], line[MAX], target_file[] = "target.txt";
    source = fopen(argv[1], "r");
    target = fopen(target_file, "w");
    if(!source)
        {
            printf("File not found\n");
            exit(0);
        }
    char c;
    while(!feof(source))
        {
            fgets(line, MAX, source);

            if(strcmp(line, "\n"))
                fprintf(target, "\n");
            mystrrev(line,rev);
            
                fprintf(target, "%s", rev);
            for(int i = 0 ; i < MAX ; i++)
                {
                    strcpy(&line[i], "\0");
                    strcpy(&rev[i], "\0");
                }
        }
    fclose(source);
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
