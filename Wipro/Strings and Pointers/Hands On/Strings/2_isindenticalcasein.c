#include<stdio.h>
#include<string.h>
#include<ctype.h>

//strcmpi() no longer included in C99, implicit declaration is invalid. 
void isidenticalstr(char str1[], char str2[])
    {
        int i = 0, flag = 0;
        while(str1[i] != '\0' && str2[i] != '\0')
            {
                if(tolower(str1[i]) == tolower(str2[i]))
                    flag = 1;
                else
                {
                    flag = 0;
                    break;
                }
                i++;
            }
        (flag == 1)?printf("**Entered strings are identical**\n"):printf("**Entered strings are not identical**\n");
    }

int main()
    {
        char str1[20],str2[20];
        
        printf("Enter the first string\n");
        scanf("%[^\n]%*c",str1);
        printf("Enter the second string\n");
        fgets(str2, 20, stdin);
        
        isidenticalstr(str1,str2);
        return 0;
    }