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
        for(int i = 0 ; i < 3 ; i++)
        {
            printf("\nData of Cricketer %d\n", i+1);
            printf("\nCricketer's name: %s\n", x[i].Name);
            printf("\nCricketer's age: %d\n", x[i].Age);
            printf("\nCricketer's highest score: %d\n", x[i].highestscore);
            printf("\nCricketer's least score: %d\n", x[i].leastscore);
            printf("\nCricketer's no of zeros: %d\n", x[i].noofzeros);
        }
    }

int main()
{
    struct CricketerdataBatsman c[3];
    int i;

    for(i = 0 ; i < 3 ; i++)
        {
            printf("\nEnter info for cricketer %d\n",i+1);
            getdata(&c[i]);
        }
    printf("\nAll Cricketers Data:\n");
    cricketerdata_print(c);

    return 0;
}