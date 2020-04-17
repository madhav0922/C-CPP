#include<stdio.h>
#include<stdlib.h>

void mystrcat(char *str1, int n, char *str2, char *str3)
    {
        int i = 0, j = -1 , digit, rev = 0;
    
        while(str1[i] != '\0')
            {
                str3[++j] = str1[i];
                i++;
            }
        i = 0;
        j--;
        while(n > 0)
            {
                digit = n % 10;
                n = n / 10;
                rev = rev * 10 + digit;
            }
        while(rev > 0)
            {
                digit = rev %10;
                rev = rev / 10;
                str3[++j] = (char)(digit+'0');
            }
        while(str2[i] != '\0')
            {
                str3[++j] = str2[i];
                i++;
            }
    }

int main()
    {
        char str1[20], str2[20], str3[50];
        int n;
        printf("Enter a string then a number and then another string\n");
        fgets(str1, 20, stdin);
        scanf("%d ",&n);
        scanf("%[^\n]%*c",str2);
        
        printf("\nConcatinated string\n");
        mystrcat(str1, n, str2, str3);
        puts(str3);
        return 0;
    }