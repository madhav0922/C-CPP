#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

typedef struct Node 
{
    int data;
    struct Node *next;
}node;

node* create_node(int data)
    {
        node* newnode = (node*)malloc(sizeof(node));
        if(!newnode)
            {
                printf("memory error\n");
                exit(0);
            }
        newnode -> data = data;
        newnode -> next = NULL;
        return(newnode);
    }

void insert(node **Head, node *newnode, int pos)
    {
        node *p;
        p = *Head;
        //insertion at beg
        if(!*Head) 
            *Head = newnode;
        else if(pos == 1)
            {
                newnode -> next = p;
                *Head = newnode;
            }
        else            //other insertions
            {
                int k = 1;
                //make the pointer reach kth or end position
                while(p -> next != NULL && k < pos)
                    {
                        k++;
                        p = p -> next;
                    }
                    
                    if(p -> next == NULL)      //p==NULL meaning end position
                        p -> next = newnode;  //insertion at end
                    else        
                        {
                            newnode -> next = p -> next;    //insertion at kth position
                            p -> next = newnode;
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
        while(temp != NULL)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            }
        }
    }

int main()
    {
        node *Head1 = NULL, *Head2 = NULL, *new = NULL;
        int data = 0, pos = 1, i = 0;
        char line[MAX] = "\0";
        FILE *source;

        source = fopen("listinput.txt", "r");

        pos = 1;

        fgets(line, MAX, source);
        
        while(line[i++] != '\n')
        {
            sscanf(line+i, "%d", &data);
            new = create_node(data);
            insert(&Head1, new, pos++);
            new = NULL;
        }

        // ch = fgetc(source);
        // while(ch != '\n')
        //     {
        //         if(ch != ' ')
        //             {
        //                 new = create_node(ch);
        //                 insert(&Head2, new, pos++);
        //                 new = NULL;
        //             }
        //         ch = fgetc(source);
        //    }
        
        display_list(Head1);
        //display_list(Head2);
        
        return 0;
    }