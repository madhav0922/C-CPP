#include <iostream>
#include <queue>
#include <stack>

using namespace std;
// void main()
// {
//     int i = 1, j = 2, k = 3, m;
//     m = ++i || ++j && ++k;
//     printf("%d,%d,%d,%d", i, j, k, m);
// }

// #define SWAP(a, b, c) \
//     c t;              \
//     t = a, a = b, b = t
// int main()
// {
//     int x = 10, y = 20;
//     SWAP(x, y, int);
//     printf("%d%d\n", x, y);
//     return 0;
// }

typedef struct Node
{
    int val;
    struct Node *left, *right;
} node;

node *newnode(int key)
{
    node *temp = new node;
    temp->val = key;
    temp->left = temp->right = NULL;
    return (temp);
}

int noofleaf(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return noofleaf(root->left) + noofleaf(root->right);
}

// // to create mirror image
// void mirror(node *root)
// {
//     node *temp;
//     if (root->left != NULL || root->right != NULL)
//     {
//         *temp = *root->left;
//         *root->left = *root->right;
//         *root->right = *temp;
//     }
//     mirror(root->left);
//     mirror(root->right);
// }

int ismirror(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;

    return (root1 && root2 && root1->val == root2->val && ismirror(root1->left, root2->right) && ismirror(root1->right, root2->left));
}

int isidentical(node *root1, node *root2)
{
    node *temp;
    if (root1 == NULL && root2 == NULL)
        return 1;

    return (root1 && root2 && root1->val == root2->val && isidentical(root1->left, root2->left) && isidentical(root1->right, root2->right));
}

void levelorder_inline(node *root)
{
    // if (root!=NULL)
    //     cout << root->val;
    // return (root && levelorder(root->left) && levelorder(root->right));
    node *k;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        cout << k->val;
        if (k->left != NULL)
            q.push(k->left);
        if (k->right != NULL)
            q.push(k->right);
    }
}

void reverselevelorder_inline(node *root)
{
    node *k;
    queue<node *> q;
    stack<int> s;
    q.push(root);
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        s.push(k->val);
        if (k->right != NULL)
            q.push(k->right);
        if (k->left != NULL)
            q.push(k->left);
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

void spiralprint_inline(node *root)
{
    node *k;
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) //since both stacks should continue until empty, otherwise only two lines will be printed.
    {
        while (!s1.empty())
        {
            k = s1.top();
            s1.pop();
            cout << k->val;
            if (k->left != NULL)
                s2.push(k->left);
            if (k->right != NULL)
                s2.push(k->right);
        }
        while (!s2.empty())
        {
            k = s2.top();
            s2.pop();
            cout << k->val;
            if (k->right != NULL)
                s1.push(k->right);
            if (k->left != NULL)
                s1.push(k->left);
        }
    }
}

int main()
{
    int k;
    node *root1 = newnode(1);
    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left = newnode(4);
    root1->left->right = newnode(5);
    root1->right->left = newnode(6);
    root1->right->right = newnode(7);
    root1->left->left->right = newnode(8);
    root1->right->right->left = newnode(9);
    node *root2 = newnode(1);
    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5);
    root2->right->left = newnode(6);
    root2->right->right = newnode(7);
    root2->left->left->right = newnode(8);
    root2->right->right->left = newnode(9);

    cout << "\n"
         << "no of leaves"
         << "\n";

    k = noofleaf(root1);
    cout << k << "\n";

    cout << "\n"
         << "is identical?"
         << "\n";

    k = isidentical(root1, root2); //two trees are identical or not
    cout << k << "\n";

    cout << "\n"
         << "is mirror?"
         << "\n";

    k = ismirror(root1, root2); //two trees are mirrored image of each other or not
    cout << k << "\n";

    cout << "\n"
         << "is symmetric?"
         << "\n";

    k = ismirror(root1, root1); //checks if a tree is symmetric or not.
    cout << k << "\n";

    cout << "\n"
         << "level order inline"
         << "\n";

    levelorder_inline(root1); //level order in single line

    cout << "\n"
         << "reverse level order inline"
         << "\n";

    reverselevelorder_inline(root1); // reverse level order inline

    // mirror(root1);
    // isidentical(root1, root1);

    cout << "\n"
         << "spiral print inline"
         << "\n";

    spiralprint_inline(root1); // reverse level order inline
    return 0;
}
