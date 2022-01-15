
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        queue<Node *> q;

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {

            Node *t = q.front();
            q.pop();

            if (t)
            {
                t->nextRight = q.front();
                if (t->left)
                {
                    q.push(t->left);
                }

                if (t->right)
                {
                    q.push(t->right);
                }
            }
            else
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
    }
};
