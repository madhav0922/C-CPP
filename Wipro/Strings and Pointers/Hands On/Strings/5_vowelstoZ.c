#include<stdio.h>

void vowelstoZ(char *str)
    {
        int i = 0;
        while(str[i] != '\0')
            {
                if(str[i]=='a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i]=='A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                    str[i] = 'z';
                i++;
            }
    }

int main()
    {
        char str[20];
        printf("Enter a string\n");
        fgets(str, 20, stdin);
        vowelstoZ(str);
        puts(str);
        return 0;
    }