#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int countTree(Node *root, int target, int &count)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left && !root->right)
    {
        if (root->data == target)
        {
            count++;
        }

        return root->data;
    }

    int ls = countTree(root->left, target, count);
    int rs = countTree(root->right, target, count);

    if (ls + rs + root->data == target)
    {
        count++;
    }

    return ls + rs + root->data;
}

int countSubtreesWithSumX(Node *root, int target)
{
    // Code here
    int count = 0;
    countTree(root, target, count);
    return count;
}