#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, int &count)
    {
        grid[i][j] = 2;

        if (i + 1 < n && grid[i + 1][j] == 1)
        {
            count++;
            dfs(i + 1, j, n, m, grid, count);
        }

        if (i - 1 >= 0 && grid[i - 1][j] == 1)
        {
            count++;
            dfs(i - 1, j, n, m, grid, count);
        }

        if (j + 1 < m && grid[i][j + 1] == 1)
        {
            count++;
            dfs(i, j + 1, n, m, grid, count);
        }

        if (j - 1 >= 0 && grid[i][j - 1] == 1)
        {
            count++;
            dfs(i, j - 1, n, m, grid, count);
        }

        if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 1)
        {
            count++;
            dfs(i - 1, j - 1, n, m, grid, count);
        }

        if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == 1)
        {
            count++;
            dfs(i + 1, j + 1, n, m, grid, count);
        }

        if (i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == 1)
        {
            count++;
            dfs(i + 1, j - 1, n, m, grid, count);
        }

        if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == 1)
        {
            count++;
            dfs(i - 1, j + 1, n, m, grid, count);
        }

        return;
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = 1;

                    dfs(i, j, n, m, grid, count);
                    res = max(res, count);
                }
            }
        }

        return res;
    }
};