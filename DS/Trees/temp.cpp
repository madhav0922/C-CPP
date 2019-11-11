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

// BST two methods for checking if a tree is a BST or not

// int inorder(node *root, queue<int> k)
// {
//     inorder(root->left);
//     k.push(root->val);
//     inorder(root->right);
// }

// int bst(node *root)
// {
//     queue<int> k;

//     inorder(root, k);
// }

bool isbst(node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->val <= min || root->val >= max)
        return false;
    return (isbst(root->left, min, root->val) && isbst(root->right, root->val, max));
}

bool isbtbst(node *root)
{
    return isbst(root, INT16_MIN, INT16_MAX);
}

int lca_bst(node *root, int a, int b)
{
    if (a < root->val && b > root->val)
        return root->val;
    else if (a < root->val && b < root->val)
        return lca_bst(root->left, a, b);
    else
        return lca_bst(root->right, a, b);
}

node *lca_binary_tree(node *root, int a, int b)
{
    node *right, *left;
    if (root == NULL)
        return NULL;
    if (root->val == a || root->val == b)
        return root;
    left = lca_binary_tree(root->left, a, b);
    right = lca_binary_tree(root->right, a, b);
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL && right != NULL)
        return root;
    return ((left != NULL) ? left : right);
}

void tree_left_view(node *root, int level, int *max_level)
{
    if (root == NULL)
        return;
    if (level > *max_level)
    {
        cout << root->val;
        *max_level = level;
    }
    tree_left_view(root->left, level + 1, max_level); // do not send address of max_level again as it will result in pointer to pointer to ... case
    tree_left_view(root->right, level + 1, max_level);
}

void left_view(node *root)
{
    int max_level = 0;
    tree_left_view(root, 1, &max_level);
}

int main()
{
    int k, n;

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

    // for BST
    node *root3 = newnode(10);
    root3->left = newnode(5);
    root3->right = newnode(15);
    root3->left->left = newnode(3);
    root3->left->right = newnode(7);
    root3->right->left = newnode(13);
    root3->right->right = newnode(20);
    root3->left->left->left = newnode(1);
    root3->right->right->right = newnode(25);

    //LCA Binary Tree
    node *root4 = newnode(3);
    root4->left = newnode(6);
    root4->right = newnode(8);
    root4->left->left = newnode(2);
    root4->left->right = newnode(11);
    root4->right->right = newnode(13);
    root4->left->right->left = newnode(9);
    root4->left->right->right = newnode(5);
    root4->right->right->left = newnode(7);

    //left view , right view
    node *root5 = newnode(3);
    root5->left = newnode(6);
    root5->right = newnode(8);
    root5->left->left = newnode(2);
    root5->left->right = newnode(11);
    root5->right->right = newnode(13);
    root5->left->right->left = newnode(9);
    root5->left->right->right = newnode(5);
    root5->right->right->left = newnode(7);
    root5->right->right->left->right = newnode(40);

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

    n = isbtbst(root3);
    cout << "\n"
         << "is bst? " << k
         << "\n";

    //LCA
    int a = 1, b = 7;
    n = lca_bst(root3, a, b);
    cout << "\n"
         << "LCA: " << n
         << "\n";

    // LCA Binary Tree
    int c = 9, d = 7;
    node *lcabt;
    lcabt = lca_binary_tree(root4, c, d);
    cout << "\n"
         << "LCA_Binary_Tree: " << lcabt->val
         << "\n";

    // left view of tree
    cout << "\n"
         << "Left View of Tree: "
         << "\n";
    left_view(root5);
    cout << "\n";
}
