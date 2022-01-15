#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool findCycle(vector<int> v[], vector<int> &col, int node)
    {
        col[node] = 1;

        for (int i = 0; i < v[node].size(); i++)
        {
            int n = v[node][i];
            if (col[n] == 0)
            {
                if (findCycle(v, col, n))
                {
                    return true;
                }
            }
            else if (col[n] == 1)
            {
                return true;
            }
        }

        col[node] = 2;
        return false;
    }

    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {

        vector<int> v[N];
        vector<int> col(N, 0);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int x = prerequisites[i].first;
            int y = prerequisites[i].second;

            v[x].push_back(y);
        }

        for (int i = 0; i < N; i++)
        {
            if (col[i] == 0)
            {
                if (findCycle(v, col, i))
                {
                    return false;
                }
            }
        }

        return true;
    }
};