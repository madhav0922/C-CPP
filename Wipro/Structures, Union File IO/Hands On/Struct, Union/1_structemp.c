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
    scanf("%[^\n]",x->empname);
    printf("Enter employee number\n");
    scanf("%d",&x->empno);
    printf("Enter employee phone number\n");
    scanf("%ld",&x->empphno);
    getchar();
}

void printdata(struct empdata *x)
    {
        printf("\nEmployee name: %s",x->empname);
        printf("\nEmployee no: %d",x->empno);
        printf("\nEmployee phone number: %ld \n",x->empphno);
    }

int main()
    {
        struct empdata e1, e2, e3;
        printf("Enter data for employee 1\n");
        getdata(&e1);
        printf("Enter data for employee 2\n");
        getdata(&e2);
        printf("Enter data for employee 3\n");
        getdata(&e3);
        printdata(&e1);
        printdata(&e2);
        printdata(&e3);
        return 0;
    }