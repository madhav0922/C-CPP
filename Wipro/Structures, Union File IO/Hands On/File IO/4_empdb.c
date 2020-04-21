#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct empdata
{
 char empname[100]; 
 char job[20];
 int empno;
 int depno;
 long int salary;
}emp; 

void getdata(emp *x)
{   
    printf("Enter employee name\n");
    fgets(x -> empname, 100, stdin);
    printf("Enter employee number\n");
    scanf("%d", &x -> empno);
    getchar();
    printf("Enter job title\n");
    fgets(x -> job, 20, stdin);
    printf("Enter department no.\n");
    scanf("%d", &x -> depno);
    printf("Enter salary\n");
    scanf("%ld", &x -> salary);
    getchar();
}

void store_data(emp *x)
{
    FILE *store;

    store = fopen("employee_db.txt","a");

    fprintf(store, "%s", x -> empname);
    fprintf(store, "%d\n", x -> empno);
    fprintf(store, "%s", x -> job);
    fprintf(store, "%d\n", x -> depno);
    fprintf(store, "%ld\n\n", x -> salary);
    
    fclose(store);
}

void printdata(emp *x)
    {
        printf("\nEmployee name: %s", x -> empname);
        printf("Employee no: %d", x -> empno);
        printf("\nJob title: %s", x -> job);
        printf("\nDepartment number: %d", x -> depno);
        printf("\nSalary: %ld\n", x -> salary);
    }

void search(char *search_name)
{
    FILE *search;
    char temp[512];
    emp display;
    search = fopen("employee_db.txt","r");
    while(fgets(temp, 512, search) != NULL)
        {
            if(strstr(temp, search_name))
                {
                    strcpy(display.empname,search_name);
                    fscanf(search, "%d %s %d %ld", &display.empno, display.job, &display.depno, &display.salary);
                }
        }
    printdata(&display);
}

int main()
{
    emp *empdata;
    int i, option, n;
    char search_name[20];
    while(1)
    {
        printf("Press: \n");
        printf("1. Enter employee data\n");
        printf("2. Retrieve employee data\n");
        printf("0. EXIT\n");
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 1: printf("\nEnter number of records you want to enter\n");
                    scanf("%d", &n);
                    getchar();
                    empdata = (emp*) malloc(n * sizeof(emp));
                    for(i = 0 ; i < n ; i++)
                        getdata(&empdata[i]);
                    for(i = 0 ; i < n ; i++)
                        store_data(&empdata[i]);
                    printf("Data stored successfully\n");
                    break;
            case 2: printf("Enter the name of employee to display details of: ");
                    fgets(search_name, 20, stdin);
                    search(search_name);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\nWrong input! Try again\n\n");
                     break;
        }
    }
    
    return 0;
}