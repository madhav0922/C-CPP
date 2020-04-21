#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studata
{
 char stuname[100]; 
 char dept[100];
 char course[100];
 int rollno;
 int yofj;
}stu; 

void getdata(stu *x, int n)
{   
    int i;
    for(i = 0; i < n ; i++)
    {
        if(i == 0)
            printf("Enter the name of %dst student: ",i+1);
        else if(i == 1)
            printf("\nEnter the name of %dnd student: ",i+1);
        else if(i == 2)
            printf("\nEnter the name of %drd student: ",i+1);
        else
            printf("\nEnter the name of %dth student: ",i+1);
        fgets(x -> stuname, 100, stdin);
        printf("Enter the Roll number: ");
        scanf("%d", &x -> rollno);
        getchar();
        printf("Enter the Dept: ");
        fgets(x -> dept, 100, stdin);
        printf("Enter the Course: ");
        fgets(x -> course, 100, stdin);
        printf("Enter the Year of Joining: ");
        scanf("%d", &x -> yofj);
        getchar();
        x++;
    }
}

void store_data(stu *x)
{
    FILE *store;

    store = fopen("studentdb.txt","a");

    fprintf(store, "%s", x -> stuname);
    fprintf(store, "%d\n", x -> rollno);
    fprintf(store, "%s", x -> dept);
    fprintf(store, "%s", x -> course);
    fprintf(store, "%d\n\n", x -> yofj);
    
    fclose(store);
}

void printdata(stu *x)
    {
        printf("\n*** Following are the details of %s ***\n", x -> stuname);
        printf("Roll No\t: %d", x -> rollno);
        printf("\nDept\t: %s", x -> dept);
        printf("\nCourse\t: %s", x -> course);
        printf("\nYear of Joining\t: %d\n", x -> yofj);
    }

void search(char *search_name)
{
    FILE *search;
    char tstu[512];
    stu display;
    search = fopen("studentdb.txt","r");
    while(fgets(tstu, 512, search) != NULL)
        {
            if(strstr(tstu, search_name))
                {
                    strcpy(display.stuname,search_name);
                    fscanf(search, "%d %s %s %d", &display.rollno, display.dept, display.course, &display.yofj);
                }
        }
    printdata(&display);
}

int main()
{
    stu *studata;
    int i, option, n;
    char search_name[20];
    while(1)
    {
        printf("Press: \n");
        printf("1. Enter student data\n");
        printf("2. Retrieve student data\n");
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 1: printf("\nEnter the number of student data you would like to update (Max Limit 100): ");
                    scanf("%d", &n);
                    getchar();
                    studata = (stu*) malloc(n * sizeof(stu));
                    
                    getdata(studata, n);
                    for(i = 0 ; i < n ; i++)
                        store_data(&studata[i]);
                    printf("\n\n***Database is successfully updated***\n\n");
                    break;
            case 2: printf("Enter the name of student to display details of: ");
                    scanf("%[^\n]s",search_name);
                    search(search_name);
                    break;
            default: printf("\nWrong input! Try again\n\n");
                     break;
        }
    }
    
    return 0;
}