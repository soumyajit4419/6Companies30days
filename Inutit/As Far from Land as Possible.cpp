#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, queue<pair<int, pair<int, int>>> q)
    {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        while (!q.empty())
        {
            int d = q.front().first;
            res = max(res, d);
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if (x + 1 < n && grid[x + 1][y] == 0)
            {
                grid[x + 1][y] = 2;
                q.push({d + 1, {x + 1, y}});
            }

            if (x - 1 >= 0 && grid[x - 1][y] == 0)
            {
                grid[x - 1][y] = 2;
                q.push({d + 1, {x - 1, y}});
            }

            if (y + 1 < m && grid[x][y + 1] == 0)
            {
                grid[x][y + 1] = 2;
                q.push({d + 1, {x, y + 1}});
            }

            if (y - 1 >= 0 && grid[x][y - 1] == 0)
            {
                grid[x][y - 1] = 2;
                q.push({d + 1, {x, y - 1}});
            }
        }

        if (res == 0)
        {
            return -1;
        }

        return res;
    }

    int maxDistance(vector<vector<int>> &grid)
    {

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    q.push({0, {i, j}});
                }
            }
        }

        return bfs(grid, q);
    }
};