#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findOrder(vector<int> v[], vector<bool> &vs, int node, stack<int> &s)
    {
        if (vs[node])
        {
            return;
        }

        vs[node] = 1;

        for (int i = 0; i < v[node].size(); i++)
        {
            int in = v[node][i];
            findOrder(v, vs, in, s);
        }

        s.push(node);
        return;
    }

    bool findCycle(vector<int> v[], int node, vector<int> &col)
    {
        if (col[node] == 2)
        {
            return false;
        }

        col[node] = 1;

        for (int i = 0; i < v[node].size(); i++)
        {
            int in = v[node][i];
            if (col[in] == 1)
            {
                return true;
            }
            else if (col[in] == 0)
            {
                if (findCycle(v, in, col))
                {
                    return true;
                }
            }
        }

        col[node] = 2;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();

        vector<int> v[numCourses];

        for (int i = 0; i < n; i++)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];

            v[y].push_back(x);
        }

        vector<int> col(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (col[i] == 0)
            {
                if (findCycle(v, i, col))
                {
                    return {};
                }
            }
        }

        stack<int> s;
        vector<bool> vs(numCourses, false);

        vector<int> res;

        for (int i = 0; i < numCourses; i++)
        {
            if (!vs[i])
            {
                findOrder(v, vs, i, s);
            }
        }

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};