#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    char file_name[256], file_content[50];
    printf("Enter the file name to be created\n");
    fgets(file_name, 256, stdin);

    memset(file_content, 0, sizeof(file_content));

    printf("Enter the file content\n");
    scanf("%50[^q]s", file_content);
    
    if(file_content[49] == '\0')
    strcat(file_content, "q");
    
    fp = fopen(file_name, "w");

    fprintf(fp, "%s",file_content);
    fclose(fp);

    printf("Data from the file is\n\n");
    fp = fopen(file_name,"r");

    char ch = getc(fp);
    while(ch != EOF)
        {
            putchar(ch);
            ch = getc(fp);
        }
    fclose(fp);
    printf("\n");
    return 0;
}