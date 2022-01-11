#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> pre;

    void preorder(Node *root)
    {
        if (!root)
        {
            pre.push_back(-1);
            return;
        }

        pre.push_back(root->data);
        preorder(root->left);
        preorder(root->right);
        return;
    }

    vector<int> serialize(Node *root)
    {

        //Your code here
        preorder(root);
        return pre;
    }

    Node *createTree(vector<int> &v, int &pos)
    {
        if (pos >= v.size() || v[pos] == -1)
        {
            pos++;
            return NULL;
        }

        Node *temp = new Node(v[pos]);
        pos++;
        temp->left = createTree(v, pos);
        temp->right = createTree(v, pos);
        return temp;
    }
    
    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &v)
    {
        //Your code here
        int n = 0;
        return createTree(v, n);
    }
};