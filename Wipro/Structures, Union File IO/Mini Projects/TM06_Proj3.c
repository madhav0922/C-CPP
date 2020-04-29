#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}
int main(int arg, char** argv)
{
char c[100000];
FILE *fptr;
fptr = fopen(argv[1],"r");
if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   int line=0;
    while (fgets(c, sizeof(c), fptr)) {
        line++;
        strtok(c, "\n");
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        char 
        *query = strdup (c),  /* duplicate array, &array is not char** */
        *tokens = query,
        *p = query;
        //printf("OOOOO%sOOOOO\n",c);
        if(strstr(c,"while"))
        printf("%d: %s\n",line,c);
    while ((p = strsep (&tokens, ";\n"))) {
        char *var = strtok (p, "="),
             *val = NULL;
        if (var && (val = strtok (NULL, "="))){
            if(strstr(c,"0;")==NULL&&strstr(c,"1;")==NULL){
            printf ("%d: %s\n", line,c);
    }
        }
        char *var1 = strtok (p, ","),
             *val1 = NULL;
        if (var1 && (val1 = strtok (NULL, ","))){
            if(strstr(c,"0;")==NULL&&strstr(c,"#define")==NULL&&strstr(c,"++")==NULL){
                if(strstr(c,"printf")!=NULL)
                if(strstr(c,"%d")==NULL)
                continue;
            printf ("%d: %s\n",line, c);
    }
        }
        }
    free (query);
        //printf("%s", c); 
    }
    fclose(fptr);
    return 0;
}