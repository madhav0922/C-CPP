#include<stdio.h>
#include<string.h>

int main()
    {
        char str1[20],str2[20];
        
        printf("Enter the first string\n");
        fgets(str1, 20, stdin);
        printf("Enter the second string\n");
        fgets(str2, 20, stdin);

        int res = strcmp(str1,str2);
        
        if(res == 0)
            printf("**Entered strings are indentical**\n");
        else
            printf("**Entered strings are not identical\n");
        
        return 0;
    }