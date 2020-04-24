#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void substring(char *str, int n)
{
    fflush(stdin);
    int i, j, k, l, count = 0, max_count = -1, flag = 0, temp = 0;
    char subs[n], max_subs[n];

    if(n == 0 || n > strlen(str))
        {
            printf("Error: Invalid length of substring\n");
            exit(0);
        }

    for(i = 0 ; i < (strlen(str)-n+1); i++)
        {
            flag = 0;
            for(k = i ; k < (i+n) ; k++)
                subs[k-i] = str[k];
            count = 0;
            for(j = 0 ; j < (strlen(str)-n+1); j++)
                {   
                    temp = 0;
                    for(l = j ; l < (j+n) ; l++)
                        {
                            if(subs[l-j] == str[l])
                                temp++;
                            else
                                temp--;
                        }
                    if(temp == n)
                        count++;
                }
            if(count >= max_count)
                {
                    max_count = count;
                    strcpy(max_subs, subs);
                    flag = 1;
                }
            if(flag)
                printf("%s:",max_subs);            
        }
    printf("\n");
}

int main(int argc, char** argv)  
{ 
    int n = atoi(argv[2]);
    substring(argv[1], n);
    return 0;
}