#include<iostream>
using namespace std;

typedef struct Node
    {
        int data;
        struct Node *next;
    }node;

node* create_node(int val)
    {
        node* newnode= new node;
        if(!newnode)
            {
                cout<<"memory error";
                exit(0);
            }
        else
            {
                newnode->data=val;
                newnode->next=NULL;
            }
        return newnode;
    }

void insert(node **Head, node *newnode)
    {
        // insertion at beginning
        //  newnode->next=*Head;
        //  *Head = newnode;

        // insertion at end
        node *p;
        p=*Head;
        if(*Head==NULL)
            *Head=newnode;
        else
        {
        while(p->next)
            {
                p=p->next;
            }
        p->next=newnode;
    }
    }

void display(node *Head)
    {
         while (Head)
            {
                cout<<Head->data;
                Head = Head->next;
            }
    }

void reverse(node **Head)
    {
        node *prev=NULL,*curr,*nxt;
        curr=*Head;
        nxt=curr->next;
        
        while(curr->next!=NULL)
            {
                curr->next=prev;
                prev=curr;
                curr=nxt;
                nxt=nxt->next;
            }
        curr->next=prev;
        *Head=curr;
    }

void swap(node *p1, node *p2)
    {
        node *temp;
        temp = p1;
        p2 = p1;
        p1 = temp;
    }

void sum(node *Head,node *Head2)
    {
        node *op1,*op2,*Head3=NULL,*newnode;
        //swap(Head,Head2);
        op1=Head;
        op2=Head2;
        static int c,add,digit; //carry
        int operand1,operand2;

        while(op1 || op2)
        {
            add = (op1 ? op1->data : 0) + (op2 ? op2->data : 0) + c;
            c=add/10;
            digit=add%10;
            newnode = create_node(digit);
            insert(&Head3,newnode);

            if(op1) op1=op1->next;
            if(op2) op2=op2->next;  
        } 
        if(c>0)
            {
                newnode = create_node(c);
                insert(&Head3,newnode);
            }
        reverse(&Head3);
        display(Head3);
    }

int main()
    {
        int data=10;
        node *newnode,*Head=NULL,*Head2=NULL;
        newnode = create_node(2);
        insert(&Head,newnode);
        newnode = create_node(3);
        insert(&Head,newnode);
        newnode = create_node(4);
        insert(&Head,newnode);
        newnode = create_node(9);
        insert(&Head2,newnode);
        newnode = create_node(9);
        insert(&Head2,newnode);
        newnode = create_node(8);
        insert(&Head2,newnode);
        newnode = create_node(9);
        insert(&Head2,newnode);
        newnode = create_node(4);
        insert(&Head2,newnode);
        display(Head);
        reverse(&Head);
        reverse(&Head2);
        display(Head);
        display(Head2);
        sum(Head,Head2);
    }