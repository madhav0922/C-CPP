#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkidentical(char *str1, char *str2)
    {
        int i = 0;
        while(str1[i] != '\0' && str2[i] != '\0')
            {
                if(tolower(str1[i]) != tolower(str2[i]))
                    return 0;
                i++;
            }
        return 1;
    }

int main()
    {
        char str1[20],str2[20];
        
        printf("Enter the first string\n");
        scanf("%[^\n]%*c",str1);
        printf("Enter the second string\n");
        fgets(str2, 20, stdin);
        
        printf("\n%d\n",checkidentical(str1,str2));
        return 0;
    }