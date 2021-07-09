// find loest comon Ancestor of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) //constructor
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// stratigy 1
bool getPath(Node *root, int key, vector<int> &path)
{

    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int path_cng;
    for (path_cng = 0; path_cng < path1.size() && path2.size(); path_cng++)
    {
        if (path1[path_cng] != path2[path_cng])
        {
            break;
        }
    }

    return path1[path_cng - 1];
}

//stratigy 2

Node *LCA2(Node *root, int n2, int n1)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n2, n1);
    Node *rightLCA = LCA2(root->right, n2, n1);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;
}

int main()
{
    /*
                1
               / \
              2   3
            /    / \
           4    5   6
               /
              7
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    int n1 = 7;
    int n2 = 6;

    //stratigy 1
    /*
    int lca = LCA(root, n1, n2);

    if (lca == -1)
    {
        cout << "LCA doesn't exist" << endl;
    }
    else
    {
        cout << "LCA: " << lca << endl;
    }
    */
    //stratigy 2

    Node *lca = LCA2(root, n1, n2);

    if (lca == NULL)
    {
        cout << "LCA doesn't exist" << endl;
    }
    else
    {
        cout << "LCA: " << lca->data << endl;
    }

    return 0;
}