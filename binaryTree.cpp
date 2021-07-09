// simple binary tre construction and it's traversal

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// pre order
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//inorder traversal
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//postorder tracersal

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
     */
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Pre-order Traversal: ";
    preorder(root);

    cout << "\n"
         << "In - order Traversal : ";
    inorder(root);

    cout << "\n"
         << "post - order Traversal : ";
    postorder(root);
    return 0;
}