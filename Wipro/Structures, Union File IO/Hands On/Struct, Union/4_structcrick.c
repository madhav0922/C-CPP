#include<stdio.h>

struct CricketerdataBatsman
{
 char Name[100]; 
 int Age; 
 int highestscore; 
 int leastscore; 
 int noofzeros; 
}; 

void getdata(struct CricketerdataBatsman *x)
{   
    printf("Enter Cricketer's Name\n");
    scanf("%s", x -> Name);
    printf("Enter Cricketer's Age\n");
    scanf("%d", &x -> Age);
    printf("Enter Cricketer's highest score\n");
    scanf("%d", &x -> highestscore);
    printf("Enter Cricketer's least score\n");
    scanf("%d", &x -> leastscore);
    printf("Enter Cricketer's no of zeros\n");
    scanf("%d", &x -> noofzeros);
}

void cricketerdata_print(struct CricketerdataBatsman *x)
    {
        printf("\nCricketer's name: %s\n", x -> Name);
        printf("\nCricketer's age: %d\n", x -> Age);
        printf("\nCricketer's highest score: %d\n", x -> highestscore);
        printf("\nCricketer's least score: %d\n", x -> leastscore);
        printf("\nCricketer's no of zeros: %d\n", x -> noofzeros);
    }

int main()
    {
        struct CricketerdataBatsman c1, c2, c3, c4, c5;
        int i;
        printf("Enter 1st Cricketer's data\n");
        getdata(&c1);
        printf("\nEnter 2nd Cricketer's data\n");
        getdata(&c2);
        printf("\nEnter 3rd Cricketer's data\n");
        getdata(&c3);
        printf("\nEnter 4th Cricketer's data\n");
        getdata(&c4);
        printf("\nEnter 5th Cricketer's data\n");
        getdata(&c5);
    
        printf("\nData of all cricketers:\n");
        printf("\n1st Cricketer's data\n");
        cricketerdata_print(&c1);
        printf("\n2nd Cricketer's data\n");
        cricketerdata_print(&c2);
        printf("\n3rd Cricketer's data\n");
        cricketerdata_print(&c3);
        printf("\n4th Cricketer's data\n");
        cricketerdata_print(&c4);
        printf("\n5th Cricketer's data\n");
        cricketerdata_print(&c5);

        return 0;
    }