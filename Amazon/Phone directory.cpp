#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct TrieNode
    {
        vector<string> arr;
        TrieNode *child[26];
    };

    TrieNode *createNode(char ch)
    {
        TrieNode *t = new TrieNode;
        for (int i = 0; i < 26; i++)
        {
            t->child[i] = NULL;
        }

        return t;
    }

    void insert(TrieNode *root, string &s)
    {
        TrieNode *itr = root;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 97;
            if (itr->child[idx])
            {
                itr = itr->child[idx];
            }
            else
            {
                itr->child[idx] = createNode(s[i]);
                itr = itr->child[idx];
            }

            itr->arr.push_back(s);
        }
        return;
    }

    vector<string> search(TrieNode *root, int idx)
    {
        if (root->child[idx])
        {
            vector<string> k = root->child[idx]->arr;
            sort(k.begin(), k.end());
            return k;
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        unordered_set<string> st;
        vector<vector<string>> res;

        TrieNode *root = createNode('/');

        for (int i = 0; i < n; i++)
        {
            if (st.find(contact[i]) == st.end())
            {
                insert(root, contact[i]);
                st.insert(contact[i]);
            }
        }

        TrieNode *r = root;
        int j = -1;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 97;

            if (r->child[idx])
            {
                res.push_back(search(r, idx));
                r = r->child[idx];
            }
            else
            {
                j = i;
                break;
            }
        }

        if (j != -1)
        {
            for (int i = j; i < s.length(); i++)
            {
                res.push_back({"0"});
            }
        }

        return res;
    }
};