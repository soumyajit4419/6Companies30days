#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> v[], int node, vector<bool> &vs)
    {
        if (vs[node])
        {
            return;
        }

        vs[node] = 1;

        for (int i = 0; i < v[node].size(); i++)
        {
            int in = v[node][i];
            if (!vs[in])
            {
                dfs(v, in, vs);
            }
        }

        return;
    }

    int isBridge(int n, vector<int> adj[], int c, int d)
    {
        // Code here
        for (int i = 0; i < adj[c].size(); i++)
        {
            if (adj[c][i] == d)
            {
                adj[c].erase(adj[c].begin() + i);
                break;
            }
        }

        for (int i = 0; i < adj[d].size(); i++)
        {
            if (adj[d][i] == c)
            {
                adj[d].erase(adj[d].begin() + i);
                break;
            }
        }

        vector<bool> vs(n, false);

        int count = 0;
        dfs(adj, d, vs);

        if (!vs[c])
        {
            return 1;
        }

        return 0;
    }
};