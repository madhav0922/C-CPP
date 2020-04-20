#include<stdio.h>

struct data1
{
 char c; 
 int x; 
};  


struct data2 
{
 char arr[10]; 
 int x; 
};  


struct data3 
{
 char arr[10];
 long int x; 
};    


struct data4 
{
 char arr[100];  
 int x;     
 long int y;  
    
};

 
struct data5 
{
 char arr[100];  
 long int y;  
 int x;     
    
};

struct data6 
{
 char arr[102];  
 int x;     
 long int y;  
    
};

int main()
    {
        printf("struct 1 size: %lu\n", sizeof(struct data1));
        printf("struct 2 size: %lu\n", sizeof(struct data2));
        printf("struct 3 size: %lu\n", sizeof(struct data3));
        printf("struct 4 size: %lu\n", sizeof(struct data4));
        printf("struct 5 size: %lu\n", sizeof(struct data5));
        printf("struct 6 size: %lu\n", sizeof(struct data6));
        return 0;
    }


/*
struct 1 size: 8
struct 2 size: 16
struct 3 size: 24
struct 4 size: 112
struct 5 size: 120
struct 6 size: 120
*/