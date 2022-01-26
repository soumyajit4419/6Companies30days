#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &pc, vector<vector<int>> &heights, int i, int j)
    {

        int n = heights.size();
        int m = heights[0].size();

        if (i + 1 < n && pc[i + 1][j] == -1 && heights[i + 1][j] >= heights[i][j])
        {
            pc[i + 1][j] = 1;
            dfs(pc, heights, i + 1, j);
        }

        if (i - 1 >= 0 && pc[i - 1][j] == -1 && heights[i - 1][j] >= heights[i][j])
        {
            pc[i - 1][j] = 1;
            dfs(pc, heights, i - 1, j);
        }

        if (j + 1 < m && pc[i][j + 1] == -1 && heights[i][j + 1] >= heights[i][j])
        {
            pc[i][j + 1] = 1;
            dfs(pc, heights, i, j + 1);
        }
        if (j - 1 >= 0 && pc[i][j - 1] == -1 && heights[i][j - 1] >= heights[i][j])
        {
            pc[i][j - 1] = 1;
            dfs(pc, heights, i, j - 1);
        }

        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res;

        vector<vector<int>> pc(n, vector<int>(m, -1));
        vector<vector<int>> at(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            pc[i][0] = 1;
            at[i][m - 1] = 1;
        }

        for (int j = 0; j < m; j++)
        {
            pc[0][j] = 1;
            at[n - 1][j] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            dfs(pc, heights, i, 0);
            dfs(at, heights, i, m - 1);
        }

        for (int i = 0; i < m; i++)
        {
            dfs(pc, heights, 0, i);
            dfs(at, heights, n - 1, i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pc[i][j] == 1 && at[i][j] == 1)
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};