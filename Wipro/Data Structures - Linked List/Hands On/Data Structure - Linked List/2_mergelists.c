#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next_p;
};

void insert(struct node **,int);
void display(struct node *);
struct node* merge(struct node **,struct node **,struct node **);
void Read_File();

struct node *list1_head_p,*list2_head_p,*list3_head_p=NULL;

int main(int argc, char **argv)
{

	FILE *fp;
	char ch;
	int c = 0;
	list1_head_p=list2_head_p=NULL;
	fp = fopen(argv[1],"r");
	for(ch=getc(fp);ch!='\n';ch=getc(fp))
	{
		if(ch!=' ')
		{
			insert(&list1_head_p,ch-48);
		}
	}
	while((fscanf(fp,"%d",&c))>0)
	{
		if(ch=='\n')
		{
			insert(&list2_head_p,c);

		 }
	}
	fclose(fp);
	printf("List-1:  ");
	display(list1_head_p);
	printf("\n");
	printf("List-2:  ");
	display(list2_head_p);
	printf("\n");
	merge(&list1_head_p,&list2_head_p,&list3_head_p);
	printf("List-3:  ");
	display(list3_head_p);
	printf("\n");
	getchar();
	return 0;
}


void insert(struct node **head,int no)
{
	struct node *p,*r;
	if(*head==NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=no;
		p->next_p=NULL;
		*head=p;
	}
	else
	{
		p=*head;
		while(p->next_p!=NULL)
		p=p->next_p;
		p->next_p=(struct node *)malloc(sizeof(struct node));
		p=p->next_p;
		p->data=no;
		p->next_p=NULL;
	}
}

void display(struct node *head)
{
	struct node *p;
	p = head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next_p;
	}
	printf("\n");
}

struct node* merge(struct node **list1_head_p,struct node **list2_head_p,struct node **list3_head_p)
{
	struct node *temp;
	if(*list2_head_p==NULL && list1_head_p!=NULL)   // if second list doesn't exist
	{
		*list3_head_p=*list1_head_p;
		return 0;
	}
	else if(*list1_head_p==NULL && list2_head_p!=NULL)    // if first list doesn't exist
	{
		*list3_head_p=*list2_head_p;
		return 0;
	}
	else if(*list1_head_p==NULL && list2_head_p==NULL)
	{
		return 0;
	}
	*list3_head_p=*list1_head_p;
	temp=*list1_head_p;
	while(temp->next_p!=NULL)
		temp=temp->next_p;
	temp->next_p=*list2_head_p;
	return (*list3_head_p);
}