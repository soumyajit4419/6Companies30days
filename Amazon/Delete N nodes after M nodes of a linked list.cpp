#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        //Add code here
        int i = 0;
        Node *p = head;
        Node *q = head;
        while (p)
        {
            int i = 0;
            while (p && i < M)
            {
                q = p;
                p = p->next;
                i++;
            }

            int j = 0;
            while (p && j < N)
            {
                p = p->next;
                j++;
            }

            q->next = p;
        }

        return;
    }
};