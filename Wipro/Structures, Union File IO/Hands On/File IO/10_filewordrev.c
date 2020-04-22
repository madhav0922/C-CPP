#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256


void reverse(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin; 
        *begin++ = *end; 
        *end-- = temp; 
    } 
} 

void reverseWords(char* s) 
{ 
    char* word_begin = NULL; 
    char* temp = s; /* temp is for word boundry */
  
    /*STEP 1 of the above algorithm */
    while (*temp) { 
        /*This condition is to make sure that the string start with 
          valid character (not space) only*/
        if ((word_begin == NULL) && (*temp != ' ')) { 
            word_begin = temp; 
        } 
        if (word_begin && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0'))) { 
            reverse(word_begin, temp); 
            word_begin = NULL; 
        } 
        temp++; 
    } /* End of while */
  
    /*STEP 2 of the above algorithm */
    //reverse(s, temp - 1); 
}

int main(int argc, char** argv)
{
    FILE *source, *target;
    char ch, word[MAX], line[MAX], target_file[] = "target.txt";
    source = fopen(argv[1], "r");
    target = fopen(target_file, "w");
    if(!source)
        {
            printf("File not found\n");
            exit(0);
        }
    
    while(!feof(source))
        {
            fgets(line, 256, source);
             if(strcmp(line, "\n"))
                fprintf(target, "\n");
            reverseWords(line);
            fprintf(target, "%s", line);
            for(int i = 0 ; i < 256 ; i++)
                {
                    strcpy(&line[i], "\0");
                }

        }
    fclose(source);
    fclose(target);

    target = fopen(target_file,"r");
    ch = getc(target);
    while(ch != EOF)
        {
            putchar(ch);
            ch = getc(target);
        }

    fclose(target);
    printf("\n");
    return 0;
}