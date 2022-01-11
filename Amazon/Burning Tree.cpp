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
    unordered_map<Node *, vector<Node *>> m;

    void createMap(Node *node, Node *parent)
    {

        if (!node)
        {
            return;
        }

        if (parent)
        {
            m[node].push_back(parent);
            m[parent].push_back(node);
        }

        createMap(node->left, node);
        createMap(node->right, node);
        return;
    }

    Node *findTarget(Node *root, int target)
    {
        if (!root)
        {
            return NULL;
        }

        if (root->data == target)
        {
            return root;
        }

        findTarget(root->left, target);
        findTarget(root->right, target);

        return NULL;
    }

    int findTime(Node *t)
    {
        queue<pair<Node *, int>> q;
        set<Node *> vs;
        vs.insert(t);
        q.push({t, 0});
        int res = 0;

        while (!q.empty())
        {
            Node *k = q.front().first;
            int time = q.front().second;
            res = max(res, time);
            q.pop();

            for (int i = 0; i < m[k].size(); i++)
            {
                if (vs.find(m[k][i]) == vs.end())
                {
                    q.push({m[k][i], time + 1});
                    vs.insert(m[k][i]);
                }
            }
        }

        return res;
    }
    int minTime(Node *root, int target)
    {
        // Your code goes here

        createMap(root, NULL);
        Node *t = findTarget(root, target);
        if (t)
        {
            return findTime(t);
        }

        return -1;
    }
};