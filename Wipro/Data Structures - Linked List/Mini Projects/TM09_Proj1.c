#include <stdio.h>
#include <stdlib.h>

struct LIST
{
	int info;
	struct LIST *next;
}*start[10]={NULL},*newptr, *ptr;

struct LIST *Create_New_LIST(int);
void Add_Elements(int);
void Print_Elements(int);
int Delete_Elements(int);
void Exit_Application();
void Read_File();
void Program_Menu();

int inf,i,dchoice,value,key,doutput; //Global variables

int main()
{
	Program_Menu();
	getchar();
}

void Program_Menu()
{
	char ch='y';
	int uchoice;
	Read_File();
	while(ch)
	{
		printf("1. Add element to the List \n");
		printf("2. Print elements of a particular Linked List\n");
		printf("3. Delete a specific element \n");
		printf("4. Exit application\n");
		printf("\nEnter your choice(1..4): ");
		scanf("%d",&uchoice);
		switch(uchoice)
		{
		case 1:
			printf("\nEnter an element(a number between 0 to 99)..... ");
			scanf("%d",&inf);
			Create_New_LIST(inf);
			Add_Elements(inf);
			break;
		case 2:
			printf("\nEnter the Linked List number..... ");
			scanf("%d",&dchoice);
			Print_Elements(dchoice);
			break;
		case 3:
			printf("\nEnter element to be deleted..... ");
			scanf("%d",&value);
			doutput = Delete_Elements(value);
			if(doutput>0)
				printf("\nElement deleted sucessfully..... \n");
			else
				printf("\nElement not presemt..... \n");
			break;
		case 4:
			Exit_Application();
			exit(1);
		default:
			printf("\nEnter a valid Choice!!!\n");
			break;
		}
		system("\npause");
		printf("\nPress any key to go to Program Menu.... \n");
		ch = getchar();
	}
	getchar();
}

struct LIST* Create_New_LIST(int n)
{
	ptr = (struct LIST*)malloc(sizeof(struct LIST));
	ptr->info = n;
	ptr->next = NULL;
	return ptr;
}

void Add_Elements(int n)
{
	key = inf/10;

	if(start[key] == NULL)
	{
		start[key]=ptr;
		printf("\nElement added sucessfully..... \n");
	}
	else
	{
		struct LIST *temp = start[key];
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		printf("\nElement added sucessfully..... \n");
	}
}

void Print_Elements(int dchoice)
{
	struct LIST *temp = start[dchoice-1];
	while(temp)
	{
		   printf("%d ",temp->info);
		   temp=temp->next;
	}
	printf("N\n");
}

int Delete_Elements(int value)
{
	struct LIST *temp = start[key],*dealloc;
	if(temp!=NULL)
	{
		if(temp->info==value)
		{
			dealloc = temp;
			temp = temp->next;
			free(dealloc);
			return(1);
		}
		else
		{
			while(temp->next)
			{
				if(temp->next->info==value)
				{
					dealloc = temp->next;
					temp->next = temp->next->next;
					free(dealloc);
					return(1);
				}
				temp = temp->next;
			}
		}
	}
	return 0;
}

void Read_File()
{
	FILE *fp;
	int c;
	fp = fopen("elementsdb.txt","r");
	while((fscanf(fp,"%d",&c))>0)
	{
		inf=c;
		Create_New_LIST(inf);
		Add_Elements(inf);
	}
	printf("\n");
	fclose(fp);
}

void Exit_Application()
{
	FILE *fp;
	fp = fopen("elementsdb.txt","w+");
	for(i=0;i<10;i++)
	{
		struct LIST *temp = start[i];
		while(temp)
		{
			fprintf(fp,"%d ",temp->info);
			temp=temp->next;
		}
	       fprintf(fp,"\n");
	}
	fclose(fp);
}
