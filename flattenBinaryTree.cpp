// given a binary tree, Flatten it into linked list in-place.
// after flattening, left of each node should point to NULL and
// right should contain text node in preorder sequence.
//(it's NOT allowed to use other data structures)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }

        t->right = temp;
    }
    flatten(root->right);
}

void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << endl;
    inorderPrint(root->right);
}

int main()
{
    /*          4
               / \
              9   6
             / \   \
            1   3   5
    */
    Node *root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(5);

    //call flatten
    flatten(root);
    cout << "Inorder Aftar flatten the tree" << endl;
    inorderPrint(root);
    cout << endl;

    return 0;
}