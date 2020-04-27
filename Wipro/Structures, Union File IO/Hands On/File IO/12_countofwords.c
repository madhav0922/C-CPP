#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1024

int main(int argc, char** argv)
 
{
    int i = 0;
    int j = 0;
    int k = 0;
    int row = 0;
    int col = 0;
    int counter = 0;
    int reset = 0;
    int match_index = 0;
    int size = 0;
    char temp[20];
 
    FILE *source;
    
    char word[400][20] = {" "};
 
    char c, ch, string[MAX];
 
    source = fopen(argv[1], "r");
    
    ch = fgetc(source);
    while(ch != EOF)
        {
            if(isalpha(ch) || ch == ' ')
                string[k++] = ch;
            ch = fgetc(source); 
        }

      size = strlen(string);
      while(i<size) 
      {
        c = string[i];    
            if(c==' ' || c == ',' || c == '\n') 
            {
                word[row][col]='\0';
                row++;
                col = 0;
            }
            else
            {
                word[row][col]=c;
                ++col;
            }
        i++;
      }
 
    word[row][col]='\0';
 
        for(i = 0; i<size; i++)
        {
            for(j = i+1; j < size; j++)
            {
                if(strcmp(word[i], word[j]) > 0)
                {
                    strcpy(temp, word[i]);
                    strcpy(word[i], word[j]);
                    strcpy(word[j], temp);
                }
            }
        }
    
    i = 0;
    match_index = 0;

    while(i < size)
    {
        counter = 1;
        j = i+1;
        while(j < size)
            {
                if(strcmp(word[i], word[j]) == 0)
                    {
                        counter++;
                        match_index = j;
                    }
                j++;
            }
        match_index++;
        printf("%s - %d, ", word[i], counter);
        i = match_index;
    }
    printf("\n");
    return 0;
}