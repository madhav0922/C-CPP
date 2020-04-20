#include<stdio.h>

struct empdata
{
    char empname[100];
    int empno;
    long int empphno;
};

void getdata(struct empdata *x)
{   
    printf("Enter employee name\n");
    scanf("%s", x->empname);
    printf("Enter employee number\n");
    scanf("%d", &x->empno);
    printf("Enter employee phone number\n");
    scanf("%ld", &x->empphno);
}

void printdata(struct empdata *x)
    {
        printf("\nEmployee name: %s", x->empname);
        printf("\nEmployee no: %d", x->empno);
        printf("\nEmployee phone number: %ld\n", x->empphno);
    }

int main()
    {
        struct empdata emp[20];
        int i;
        for(i = 0 ; i < 20 ; i++)
            {
                printf("\nEnter data for employee %d\n", i+1);
                getdata(&emp[i]);
            }
        
        printf("\nData of all employees:\n");

        for(i = 0 ; i < 20 ; i++)
            printdata(&emp[i]);

        return 0;
    }