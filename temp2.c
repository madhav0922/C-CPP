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
        newnode->data=data;
        printf("%d",newnode->data);
        newnode->next=NULL;
        return(newnode);
    }

void insert(node **Head, node *newnode)
    {
        //int i;
        node *p,*q;
        p = *Head;
        //q=Head->next;
        //insertion at beginning
        // newnode->next=*Head;
        // *Head=newnode;

        //insertion at end
        while(p!=NULL)
            {
                q=p;
                p=p->next;
            }
        if(p==NULL)
        {
            q->next=newnode;
            newnode->next=NULL;
        }
        else
            {
                q->next=newnode;
                newnode->next=p;
            }
        //insertion at kth position
        // while(p!=NULL && i<Pos)
        //     {
        //         p=p->next;
        //         q=q->next;
        //     }                               // using single pointer
        // p->next=newnode;                    // newnode->next=p->next;
        // newnode->next=q;                    // p->next=newnode;
    
    }

void display_list(node *Head)
    {
        node *temp;
        if(!(Head))
            printf("list is empty");
        else
        {
        temp=Head;
        while(temp->next!=NULL)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            }
        }
    }

// void reverse_list(node* head)
//     {
//         node *curr,*prev,*nxt;
//         prev->next=NULL;
//         while(prev->next==NULL)
//         {
//             curr->next=prev;
//             curr=nxt;
//             nxt=curr->next;
//         }
//        // print(head);
//     }

// int sum(node *head1, node *head2)
//     {

//     }

int main()
    {
        node *Head, *Head2, *new, *new2;
        int data = 10;
        new = create_node(data);
        insert(&Head,new);  //also take position for inserting in between
        // printf("%d",new2->data);
        // new = create_node(3);
        // insert(&Head,new);
        // new = create_node(4);
        // insert(&Head,new);
        // new = create_node(9);
        // insert(&Head2,new);
        // new = create_node(9);
        // insert(&Head2,new);
        // new = create_node(8);
        // insert(&Head2,new);
        // new = create_node(9);
        // insert(&Head2,new);
        // new = create_node(4);
        // insert(&Head2,new);

        //display_list(Head);
        //print(Head2);
    
    }

/*

reversal ite rec
ends with loop or not
ends with loop hai to starting node of the loop?
union/intersection of two LL
quick sort/sorting of LL
intersection point of two LL
number is represented in SLL +1
two numbers represented in SLL, add them

Trees poora bhai poora
top view and bottom view
sprial printing botton to top and vice versa
lowest common ancestor
tree creation with inorder and preorder / inorder and postorder
avl tree insertion deletion selection
predecessor successor
mirror and is_mirror
identical and is_identical
diameter of tree
diagonal printing
horizontal/vertical width
vertical view map


*/