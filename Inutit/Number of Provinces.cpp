#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected)
    {
        for (int i = 0; i < isConnected[node].size(); i++)
        {

            if (isConnected[node][i] == 1)
            {
                isConnected[node][i] = 2;
                isConnected[i][node] = 2;

                dfs(i, isConnected);
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m = isConnected[0].size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (isConnected[i][j] == 1)
                {
                    isConnected[i][j] = 2;
                    isConnected[j][i] = 2;
                    count++;
                    dfs(j, isConnected);
                }
            }
        }

        return count;
    }
};