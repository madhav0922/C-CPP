#include <stdio.h>  
#include <string.h>  
#define MIN(x, y) (((x) < (y)) ? (x) : (y))  
//User-defined substring function that will take string(str), position(p) and no of character(len) as input  
//Produces result c as output  
void substring(char s[], char sub[], int p, int len)
{  
    int c = 0;  
        while (c < len) 
        {  
            sub[c] = s[p+c];  
            c++;  
        }  
    sub[c] = '\0';  
}  
  
//Function thats gives the longest common prefix among two strings.  
int lcp(char s[], char t[],char a[])
{  
    int n = MIN(strlen(s),strlen(t));  
    for(int i = 0; i < n; i++)
        {  
            if(s[i] != t[i])
            {  
                substring(s,a,0,i);  
                return 0;  
            }  
        }  
    substring(s,a,0,n);  
    return 0;  
}  
  
int main()  
{  
    char str[] = "helloredhellogreenhelloyellow";  
    char lrs[100], x[100], res[100], sub[100], sub1[100];  
    int i,j,n = strlen(str);  
    for(i = 0; i < n; i++){  
    for(j = i+1; j < n; j++){  
        //For comparing each substring with every other substring  
    substring(str,sub,i,n);  
    substring(str,sub1,j,n);  
    lcp(sub,sub1,x);  
        //lrs keeps track of the longest repeating sequence  
        if(strlen(x) > strlen(lrs)) strncpy(lrs, x, strlen(x));  
 }  
}  
printf("Longest repeating sequence: %s\n",lrs);  
  return 0;  
}  