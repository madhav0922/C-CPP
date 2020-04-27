#include<stdio.h>
#include<stdlib.h>

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

void delete_node(node **Head, int pos)
    {
        node *p,*q;
        p=*Head;
        //deletion from beginning
        if(pos == 1)
            {
                *Head = p -> next;
                free(p);
                p = NULL;
            }
        else
            {
                int k = 1;
                node *temp;
                while(p && k < pos)
                    {
                        k++;
                        q = p;
                        p = p->next;
                    }
                if(!p)
                {
                    printf("Position does not exist\n");
                }
                else
                {
                    q->next = p->next;  // temp = p->next;              //deletion from kth node and end
                    free(p);            // p->next = p->next->next;     //using single pointer
                    p = NULL;           // free(temp);
                                        // temp=NULL;
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

void search(node *Head, int element)
{
    node* temp;
    int pos = 0, flag = 0;
    if(!Head)
        printf("list is empty");
    else
    {
        temp = Head;
        while(temp != NULL)
            {
                pos++;
                if(temp -> data == element)
                    {
                        printf("Data %d found at position %d.\n", element, pos);
                        flag = 1;
                    }
                temp = temp -> next;
            }
        if(!flag)
            printf("Data %d not found.\n", element);
    }
}

int main()
    {
        node *Head = NULL, *Head2, *new = NULL, *new2;
        int data = 0, ch, ch1, pos = 1, node_count = 0, element = 0;
        while(ch < 7 || !ch)
        {
        printf("MENU - Linked List\n\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Insert Node\n");
        printf("4. Display Node\n");
        printf("5. Search Data\n");
        printf("6. EXIT\n");
        printf("  Enter your option (1..6): ");

        scanf("%d", &ch);
        printf("\n");
        switch(ch)
            {
                case 1: printf("---- Add Node ----\n");
                        printf("\nEnter data for new node: ");
                        scanf("%d", &data);
                        printf("\n");
                        new = create_node(data);
                        if(!Head)
                            {
                                insert(&Head, new, 1);
                                printf("\n!!! First node automatically inserted at beginning. !!!\n\n");
                                new = NULL;
                            }
                        break;
                case 2: printf("---- Delete Node ----\n");
                        if(!Head)
                            {
                                printf("!!! List is empty. !!!\n\n");
                                break;
                            }
                        printf("\nEnter position of the node to be deleted: ");
                        scanf("%d", &pos);
                        delete_node(&Head, pos);
                        printf("\n");
                        break;
                case 3: if(!new)
                            {
                                printf("Please add a node first!\n\n");
                                break;
                            }
                        else
                            printf("Value %d will be inserted\n\n", data);
                        printf("---- Insert Node ----\n\n");
                        printf("1. Insert at beginning\n");
                        printf("2. Insert at end\n");
                        printf("3. Insert at position\n\n");
                        scanf("%d",&ch1);
                        switch(ch1)
                            {
                                case 1: printf("\n-- Insert at beginning --\n\n");
                                        pos = 1;
                                        insert(&Head, new, pos);
                                        break;
                                case 2: printf("\n-- Insert at end --\n");
                                        insert(&Head, new, 0);
                                        break;
                                case 3: printf("\n-- Insert at position-- \n");
                                        printf("Enter position to insert new node at: ");
                                        scanf("%d", &pos);
                                        insert(&Head, new, pos);
                                        break;
                                default: printf("Wrong Choice!\n");
                                         break;
                            }  
                        break;
                case 4: printf("---- Display Node ----\n\n");
                        display_list(Head);
                        printf("\n\n");
                        break;
                case 5: printf("---- Search Data ----\n\n");
                        printf("Enter the element to be searched: ");
                        scanf("%d", &element);
                        printf("\n");
                        search(Head, element);
                        printf("\n\n");
                        break;
                case 6: exit(0);
                        break;
                default: printf("!! Wrong Choice !!\n\n");
                         break;
            }
        }

        return 0;
    }
