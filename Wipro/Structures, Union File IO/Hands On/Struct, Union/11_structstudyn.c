#include<stdio.h>
#include<stdlib.h>

struct studentdata
{
       int marks[10]; 
       char name[30]; 
        int age; 
}; 

void getdata(struct studentdata *x)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("\nEnter information for student %d:\n\n", i+1);
        printf("Enter marks in 10 subjects\n");
        for(int j = 0 ; j < 10 ; j++)
            scanf("%d", &x -> marks[j]);
        getchar();
        printf("\nEnter name\n");
        scanf("%[^\n]", x -> name);
        printf("\nEnter age\n");
        scanf("%d",&x -> age);
        x++;
    }
}

void display_struct(struct studentdata *x)
    {
        for(int i = 0 ; i < 5 ; i++)
        {
            printf("\nInformation of student %d:\n",i+1);
            printf("\nMarks in 10 subjects\n");
            for(int j = 0 ; j < 10 ; j++)
                printf("%d ", x -> marks[j]);
            printf("\n\nName: %s\n", x -> name);
            printf("\nAge: %d\n", x -> age);
            x++;
        }
    }

int main()
{
    struct studentdata *stu;
    int i;
    stu = malloc (sizeof(struct studentdata) * 5);

    getdata(stu);

    display_struct(stu);    
    return 0;
}