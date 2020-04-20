#include<stdio.h>

int main()
{
    FILE *source;
    char str[20];
    int flag = 0;
    printf("Enter the string to search\n");
    scanf("%[^\n]s",str);

    source = fopen("abc","r");
    
    while(!feof(source))
        {
            if(fscanf(source, "%s", str))
                flag = 1;
        }
    if(flag == 1)
        printf("STRING FOUND\n");
    else
        printf("STRING NOT FOUND\n");
    return 0;
}
