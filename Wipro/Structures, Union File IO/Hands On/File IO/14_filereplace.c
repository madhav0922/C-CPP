#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

int main(int argc, char** argv)
{
    FILE *source, *copy;
    char line[MAX], ch; 
    int i = 1, n;
    fflush(stdin);
    printf("Enter the line number where content has to be replaced: ");
    scanf("%d", &n);
    source = fopen(argv[1], "r");
    copy = fopen("copy.txt", "w");
    if(!source)
        {
            printf("File not found\n");
            exit(0);
        }
    
     while(!feof(source))
         {
            fgets(line, MAX, source);
            if(i++ == n)
                {
                    fprintf(copy, "%s", "\0");
                    fprintf(copy, "%s\n", argv[2]);
                }
            else
            fprintf(copy, "%s", line);
            for(int j = 0 ; j < MAX ; j++)
                {
                    strcpy(&line[j], "\0");
                }
         }
    remove(argv[1]);
    fclose(source);
    fclose(copy);
    copy = fopen("copy.txt","r");
    ch = getc(copy);
    while(ch != EOF)
        {
            putchar(ch);
            ch = getc(copy);
        }
    fclose(copy);
    rename("copy.txt",argv[1]);
    printf("\n");
    return 0;
}
