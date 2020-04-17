#include<stdio.h>

int comparestr(const char *s1, const char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return 0;
        s1++;
        s2++;
    }
    return (*s2 == '\0');
}

const char *my_strstr(const char *s1 , const char *s2)
    {
        while(*s1 != '\0')
            {
                if((*s1 == *s2) && comparestr(s1, s2))
                    return s2;
                s1++;
            }
        return NULL;
    }

int main(int argc, char** argv)
{
    printf("%s\n",my_strstr(argv[1], argv[2]));
    
    return 0;
}