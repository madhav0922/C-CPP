#include<stdio.h>
#include<string.h>

int main()
{
    FILE *source;
    char str[512], temp[512], file_name[256];
    int flag = 0;

    //memcpy(file_name, "\0", sizeof(file_name));
    printf("Enter the string to search\n");
    fgets(str, 512, stdin); 
    printf("Enter the name of the file in which the string has to be searched: ");
    scanf("%[^\n]",file_name);
    
    source = fopen(file_name,"r");
    
    while(fgets(temp, 512, source) != NULL)
        {
            if(strstr(temp, str))
                flag = 1;
        }
        
    if(flag == 1)
        printf("STRING FOUND\n");
    else
        printf("STRING NOT FOUND\n");
    return 0;
}
