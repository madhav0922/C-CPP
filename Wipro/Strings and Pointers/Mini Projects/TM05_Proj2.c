#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isvowel(char *x)
{
    if (*x == 'a' || *x == 'e' || *x == 'i' || *x == 'o' || *x == 'u' || *x == 'A' || *x == 'E' || *x == 'I' || *x == 'O' || *x == 'U')
        return 1;
    return 0;
}

int myatoi(char *a)
    {
        int n = (int)*a;
        return n;
    }

void weight(char *input1, char *input2)
{
    int i,j, sum = 0;
    int vowel = (int)(*input2-'0'); 
    for(i = 0 ; i < strlen(input1) ; i++)
    {
        if(vowel)
        {
            if(myatoi(&input1[i]) >= 65 && myatoi(&input1[i]) <= 90)
                sum = sum + (myatoi(&input1[i]) % 64);
            else if(myatoi(&input1[i]) >= 97 && myatoi(&input1[i]) <= 122)
                sum = sum + (myatoi(&input1[i]) % 96);
        }
        else
        {
            if(!isvowel(&input1[i]))
            {
                if(myatoi(&input1[i]) >= 65 && myatoi(&input1[i]) <= 90)
                    sum += myatoi(&input1[i]) % 64;
                else if(myatoi(&input1[i]) >= 97 && myatoi(&input1[i]) <= 122)
                    sum += myatoi(&input1[i]) % 96;  
            }
        }
    }
    printf("%d\n",sum);
}

int main()
{
    char input1[10000], input2;

    printf("Enter a string: ");
    fgets(input1, 20, stdin);

    printf("Press\n0: Vowels to be excluded\n1. Vowels to be included\n");
    scanf("%c",&input2);

    weight(input1, &input2);
    return 0;
}