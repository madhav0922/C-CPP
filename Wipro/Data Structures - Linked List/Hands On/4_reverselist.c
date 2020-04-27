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
        temp = Head;
        while(temp -> next != NULL)
            {
                printf("%d -> ",temp->data);
                temp = temp -> next;
            }
        printf("%d", temp -> data);
        }
    }

void reverse_list(node** list_head)
    {
        node* current ;
        current = *list_head; 
        node *prev = NULL, *nxt = NULL; 
  
        while (current != NULL) { 
            // Store next 
            nxt = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = nxt; 
        } 
        *list_head = prev; 
    }

int main(int argc, char **argv)
    {
        node *Head = NULL, *new = NULL;
        fflush(stdin);
        int data = 0, pos = 1, i = 0;
        char line[MAX] = "\0";
        FILE *source;

        source = fopen(argv[1], "r");

        pos = 1;
        while(!feof(source))
        {
            fscanf(source, "%d", &data);
            new = create_node(data);
            insert(&Head, new, pos);
            pos++;
            new = NULL;
        }
        
        printf("original: ");
        display_list(Head);

        reverse_list(&Head);

        printf("\nreversed: ");
        display_list(Head);
        printf("\n");
        return 0;
    }