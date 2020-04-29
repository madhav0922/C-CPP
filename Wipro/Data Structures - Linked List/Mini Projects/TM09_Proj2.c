#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int global_pos = 0;

typedef struct Node 
{
    char name[50];
    long int mobileno;
    struct Node *next;
}node;
 
node* create_node(char name[50], long int mno)
    {
        node* newnode = (node*)malloc(sizeof(node));
        if(!newnode)
            {
                printf("memory error\n");
                exit(0);
            }
        strcpy(newnode -> name, name);
        newnode -> mobileno = mno;
        newnode -> next = NULL;
        return(newnode);
    }

void insert(node **Head, node *newnode, int pos)
    {
        node *p, *q;
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

void delete_node(node **Head, int pos)
    {
        node *p,*q;
        p = *Head;
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
        temp = Head;
        while(temp != NULL)
            {
                printf("%s ",temp -> name);
                printf("%ld\n", temp -> mobileno);
                temp = temp -> next;
            }
        }
    }

int search(node *Head, char name[50])
{
    node* temp;
    int pos = 0, flag = 0, count = 0, count_pos = 0;
    if(!Head)
        printf("list is empty");
    else
    {
        temp = Head;
        while(temp != NULL)
            {
                pos++;
                if(strcmp(temp -> name, name) == 0)
                    {
                        count++;
                        count_pos = pos;
                        printf("%s %ld\n", temp -> name, temp -> mobileno);
                        flag = 1;
                    }
                temp = temp -> next;
            }
        if(!flag)
            printf("Customer not present.\n");
    }
    if(count == 1)
        return count_pos;
    
    return 0; 
}

void read_file(node **Head)
{
    node *new;
    char name[50];
    long int mno;
    FILE *source;
    source = fopen("customerdb.txt", "r");
    fflush(source);
    fseek(source, 0, SEEK_SET);
    while(!feof(source))
    {
        fscanf(source, "%s", name);
        fgetc(source);
        fscanf(source, "%ld", &mno);
        fgetc(source);
        new = create_node(name, mno);
        insert(Head, new, ++global_pos);
    }

    fclose(source);
}

void write_file(node *Head)
    {
        FILE *target;
        node *temp;
        target = fopen("copy2.txt", "w");
        fflush(target);
        temp = Head;
        while(temp != NULL)
            {
                fprintf(target, "%s", temp -> name);
                fprintf(target, " %ld", temp -> mobileno);
                fprintf(target, "\n");
                temp = temp -> next;
            }
        
        remove("customerdb.txt");
        rename("copy2.txt", "customerdb.txt");
        fclose(target);
    }

int main()
    {
        node *Head = NULL, *new = NULL;
        int  ch, pos = 1, element = 0, count_pos = 0;
        long int mno;
        char name[50];
        FILE *source;
        fflush(stdin);
        read_file(&Head);

        while(ch < 6 || !ch)
        {
        printf("MENU - Linked List\n\n");
        printf("1. Add a new customer\n");
        printf("2. Search a customer by name\n");
        printf("3. Delete a customer record by name\n"); 
        printf("4. Print details of all customers\n");
        printf("5. Exit from the application.\n");
        printf("  Enter your option (1..5): ");

        scanf("%d", &ch);
        printf("\n");
        switch(ch)
            {
                case 1: printf("---- Add a new customer ----\n");
                        getchar();
                        printf("\nEnter customer name: ");
                        scanf("%[^\n]s", name);
                        printf("\nEnter customer mobile number: ");
                        scanf("%ld", &mno);
                        printf("\n");
                        new = create_node(name, mno);
                        insert(&Head, new, ++global_pos);
                        break;
                case 2: printf("---- Search a customer by name ----\n\n");
                        getchar();
                        printf("Enter the name of the person to be searched: ");
                        scanf("%[^\n]s", name);
                        printf("\n");
                        search(Head, name);
                        printf("\n");
                        break;
                case 3: printf("---- Delete a customer record by name ----\n");
                        if(!Head)
                            {
                                printf("!!! List is empty. !!!\n\n");
                                break;
                            }
                        getchar();
                        printf("\nEnter the name of person whose record is to be deleted: ");
                        scanf("%[^\n]s", name);
                        printf("\n");
                        count_pos = search(Head, name);
                        if(count_pos)
                            {
                                delete_node(&Head, count_pos);
                                global_pos--;
                                printf("\n!! Customer record deleted !!\n");
                            }
                        else
                            printf("\nMultiple customers with same name.\n");
                        printf("\n");
                        break;  
                case 4: printf("---- Details of all customers ----\n\n");
                        display_list(Head);
                        printf("\n\n");
                        break;
                case 5: write_file(Head);
                        exit(0);
                        break;
                default: printf("!! Wrong Choice !!\n\n");
                         break;
            }
        }

        return 0;
    }
