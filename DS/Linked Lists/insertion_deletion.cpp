#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}node;

//node *Head=NULL;

// void reverse(node *curr, node *prev)
//     {
//         if(curr)
//         {
//             reverse(prev->next,curr->next);
//                 curr->next = prev;
//         }
//         else
//         {
//             Head = prev;
//         }
//     }

void insert(node **Head,int val,int pos=1)
    {
        node *newnode = new node;
        newnode->data=val;
        newnode->next=NULL;
        node *p;
        p=*Head;
        //insertion at beg
        if(!*Head) 
            *Head = newnode;
        else if(pos==1)
            {
                newnode->next=p;
                *Head = newnode;
            }
        else            //other insertions
            {
                int k = 1;
                //make the pointer reach kth or end position
                while(p->next!=NULL && k<pos)
                    {
                        k++;
                        p = p->next;
                    }
                    
                    if(p->next==NULL)      //p==NULL meaning end position
                        p->next = newnode;  //insertion at end
                    else        
                        {
                            newnode->next = p->next;    //insertion at kth position
                            p->next = newnode;
                        }
            }
    }

void delete_node(node **Head, int pos=1)
    {
        node *p,*q;
        p=*Head;
        //deletion from beginning
        if(pos==1)
            {
                *Head = p -> next;
                free(p);
                p = NULL;
            }
        else
            {
                int k=1;
                node *temp;
                while(p && k<pos)
                    {
                        k++;
                        q = p;
                        p = p->next;
                    }
                if(!p)
                {
                    cout<<"Position does not exist";
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

void display(node *Head)
    {
        while(Head)
            {
                cout<<Head->data;
                Head=Head->next;
            }
        cout<<endl;
        return;
    }

int main()
    {
        node *Head = NULL;
        insert(&Head,10,1);
        insert(&Head,20,2);
        insert(&Head,30,3);
        display(Head);
        delete_node(&Head,2);
        display(Head);
        //reverse(Head,NULL);
        display(Head);
    }