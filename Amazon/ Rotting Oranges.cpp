#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(queue<pair<pair<int, int>, int>> &q, int n, int m, vector<vector<int>> &v)
    {
        int time = 0;
        while (!q.empty())
        {
            time = q.front().second;
            int x = q.front().first.first;
            int y = q.front().first.second;
            q.pop();

            if (x + 1 < n && v[x + 1][y] == 1)
            {
                v[x + 1][y] = 2;
                q.push({{x + 1, y}, time + 1});
            }

            if (x - 1 >= 0 && v[x - 1][y] == 1)
            {
                v[x - 1][y] = 2;
                q.push({{x - 1, y}, time + 1});
            }

            if (y + 1 < m && v[x][y + 1] == 1)
            {
                v[x][y + 1] = 2;
                q.push({{x, y + 1}, time + 1});
            }

            if (y - 1 >= 0 && v[x][y - 1] == 1)
            {
                v[x][y - 1] = 2;
                q.push({{x, y - 1}, time + 1});
            }
        }

        return time;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        int t = bfs(q, n, m, grid);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return t;
    }
};