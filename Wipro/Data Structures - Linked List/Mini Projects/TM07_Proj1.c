#include<stdio.h>
#include<stdlib.h>

typedef struct NodeHash
{
    int data;
    struct NodeHash *list_next;
    struct NodeHash *next;
}node;

node* create_node(int data)
{
    node *newnode = (node*) malloc(sizeof(node));
    if(!newnode)
        {
            printf("Node could not be created\n\n");
            exit(0);
        }
    newnode -> data = data;
    newnode -> list_next = NULL;
    newnode -> next = NULL;
    return newnode;
}

void insert(node **Head, node *newnode, int pos)
    {
        node *p, *q;
        p = *Head;
        if(!*Head)
            *Head = newnode;
        else if (pos == 1)
            {
                p -> list_next = newnode;
            }
        else
            {
                int k = 1;
                //make the pointer reach kth or end position
                while(p -> list_next != NULL && k < pos)
                    {
                        k++;
                        q = p;
                        p = p -> list_next;
                    }
                    
                    if(p -> list_next == NULL)      //p==NULL meaning end position
                        p -> list_next = newnode;  //insertion at end
                    else        
                        {
                            newnode -> list_next = p;    //insertion at kth position
                            q -> list_next = newnode;
                        }
            }
    }


void insert_next(node **Head, node *newnode, int pos)
    {
        node *p, *q;
        p = *Head;
        if(!*Head)
            *Head = newnode;
        else if (pos == 1)
            {
                p -> next = newnode;
            }
        else
            {
                int k = 1;
                //make the pointer reach kth or end position
                while(p -> next != NULL && k < pos)
                    {
                        k++;
                        q = p;
                        p = p -> next;
                    }
                    
                    if(p -> next == NULL)      //p==NULL meaning end position
                        p -> next = newnode;  //insertion at end
                    else        
                        {
                            newnode -> next = p;    //insertion at kth position
                            q -> next = newnode;
                        }
            }
    }

void display_list(node *Head)
    {
        node *temp;
        if(!(Head))
            printf("!! List is empty !!");
        else
        {
        temp=Head;
        while(temp -> next != NULL)
            {
                printf("%d -> ",temp -> data);
                temp = temp -> next;
            }
            printf("%d", temp -> data);
        }
    }

int main()
{
    FILE *source;
    int data, pos, in_pos;
    char end = '\0', end2 = '\0';
    node *Head = NULL;
    source = fopen("input.txt","r");
    if(!source)
        {
            printf("!! File not found !!\n");
            exit(0);
        }
    while(!feof(source) && data != 'N')
    {
        pos = 1;
        fscanf(source, "%d", &data);
        printf("%d",data);
        // if(end == 'N')
        // {
        //     fscanf(source, "%d %c", &data, &end);
        // }
        node *new = create_node(data);
        insert_next(&Head, new, pos++);
        in_pos = 1;
        //end2 = 'M';
        while(!feof(source) && data != 'N')
            {
                fscanf(source, "%d", &data);
                node *new = create_node(data);
                insert(&Head, new, in_pos++);       
            }
    }
    display_list(Head);
    return 0;
}