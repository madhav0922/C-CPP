#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void insert(node **Head, int val, int pos = 1)
    {
        node *newnode = new node;
        newnode -> data = val;
        newnode -> next = NULL;
        node *p;
        p = *Head;
        if(!newnode)
            {
                cout<<"Memory error\n";
                exit(0);
            }
        //insertion at beginning
        if(!p)
        {
            *Head = newnode;
        }
        else if(pos == 1)
        {
            newnode -> next = p;
            *Head = newnode;
        }
        else
        {
            //traversal of pointer
            int k = 1;
            while(p->next && k<pos)
                {
                    p = p->next;
                    k++;
                }
            //insertion at end
            if(p->next == NULL)
                p->next = newnode;
            //insertion at kth position
            else
            {
                newnode -> next = p -> next;
                p -> next = newnode;
            }
        }
    }

void delete_node(node **Head, int pos = 1)
    {
        node *p, *q;
        p = *Head;
        if(!Head)
            cout<<"List is Empty";
        //deletion from beginning
        if(pos == 1)
            {
                *Head = p -> next;
                free(p);
                p= NULL;
            }
        else
        {
            int k=1;
                while(p->next && k<pos)
                    {
                        k++;
                        q=p;
                        p=p->next;
                    }
                //deletion from end
                if(p->next == NULL)
                    {
                        q -> next = NULL;
                        free(p);
                        p = NULL;
                    }
                // deletion from kth node
                else
                {
                    q ->next = p -> next;
                    free(p);
                    p = NULL;
                }
        }
        
    }
void display(node *Head)
    {
        while(Head)
            {
                cout<<Head->data;
                Head=Head->next;
            }
            cout<<endl;
    }

void reverse(node **Head)
    {
        node *prev=NULL, *curr, *nxt;
        curr = *Head;
        nxt = curr -> next;
        while(curr->next)
            {
                curr -> next = prev;
                prev = curr;
                curr = nxt;
                nxt = nxt -> next;
            }
        curr -> next = prev;
        *Head = curr;
    }

int main()
    {
        node *Head = NULL;
        insert(&Head,10);
        insert(&Head,20);
        insert(&Head,30);
        display(Head);
        delete_node(&Head,2);
        display(Head);
        reverse(&Head);
        display(Head);
    }