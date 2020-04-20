#include<stdio.h>

struct studentdata
{
    char StudentName[100];
    int SRollno;
    int mark1;
    int mark2;
    int mark3;
};

void getdata(struct studentdata *x)
{   
    printf("Enter student name\n");
    scanf("%s", x->StudentName);
    printf("Enter student roll number\n");
    scanf("%d", &x->SRollno);
    printf("Enter marks in first subject\n");
    scanf("%d", &x->mark1);
    printf("Enter marks in second subject\n");
    scanf("%d", &x->mark2);
    printf("Enter marks in third subject\n");
    scanf("%d", &x->mark3);
}


void min_max_avg(struct studentdata *studarr)
    {
        int i, avg ,min_avg, max_avg, max_avg_index, min_avg_index;
        
        max_avg = min_avg = (studarr[0].mark1 + studarr[0].mark2 + studarr[0].mark3) / 3;
        for(i = 0 ; i < 3 ; i++)
            {
                avg = (studarr[i].mark1 + studarr[i].mark2 + studarr[i].mark3) / 3;
                if(avg > max_avg)
                    {
                        max_avg = avg;
                        max_avg_index = i;
                    }
                else if(avg < min_avg)
                    {
                        min_avg = avg;
                        min_avg_index = i;
                    }
                printf("\nAvg of student %d : %d\n", i+1, avg);
            }
        
        printf("\nStudent name with highest avg mark: %s\n", studarr[max_avg_index].StudentName);
        printf("\nStudent name with least avg mark: %s\n" , studarr[min_avg_index].StudentName);
    }

int main()
    {
        struct studentdata students[3];
        int i;
        for(i = 0 ; i < 3 ; i++)
            {
                printf("\nEnter data for student %d\n", i+1);
                getdata(&students[i]);
            }
        
        min_max_avg(students);

        return 0;
    }