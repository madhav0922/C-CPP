#include<stdio.h>

void mystrcat(char *str1, char *str2, char *str3)
    {
        int i = 0, j = 0;
        while(str1[i] != '\0')
            {
                str3[j] = str1[i];
                i++;
                j++;
            }
        i = 0;
        j--;
        while(str2[i] != '\0')
            {
                str3[j] = str2[i];
                i++;
                j++;
            }
    }

int main()
    {
        char str1[20], str2[20], str3[40];
        printf("Enter the first string\n");
        fgets(str1, 20, stdin);
        printf("Enter the second string\n");
        fgets(str2, 20, stdin);

        printf("\nConcatinated string\n");
        mystrcat(str1, str2, str3);
        puts(str3);
        return 0;
    }