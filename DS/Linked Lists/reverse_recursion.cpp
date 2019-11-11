#include <iostream>
using namespace std;

typedef struct Node
    {
        int data;
        struct Node *next;
    }node;

struct LinkedList
{
    node *Head = NULL ;

    void insert(int val)
        {
            //insertion at beginning
            node *newnode =new node;
            newnode -> data =val;
            newnode -> next = NULL;
            node *p;
            p = Head;
            if(!p)
                Head = newnode;
            else
            {
                newnode -> next = p;
                Head = newnode;
            }
        }

    void display()
        {
            while(Head)
                {
                    cout<<Head -> data;
                    Head = Head -> next;
                }
        }
    
    void reverse(node *curr, node *prev = NULL)
        {
            if(!curr)
                {
                    Head = prev;
                }
            else
                {
                    reverse(prev -> next, curr -> next);
                    curr -> next = prev;
                }
        }
};

int main()
    {
        LinkedList l1;
        l1.insert(10);
        l1.insert(20);
        l1.insert(30);
        l1.display();
        l1.reverse(l1.Head,NULL);
        l1.display();
    }