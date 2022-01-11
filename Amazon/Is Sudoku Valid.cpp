#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRowVal(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    if (s.find(mat[i][j]) == s.end())
                    {
                        s.insert(mat[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isColVal(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < m; j++)
            {
                if (mat[j][i] != 0)
                {
                    if (s.find(mat[j][i]) == s.end())
                    {
                        s.insert(mat[j][i]);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool checkBlock(vector<vector<int>> &mat, int x, int y)
    {
        unordered_set<int> s;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if (mat[i][j] != 0)
                {
                    if (s.find(mat[i][j]) == s.end())
                    {
                        s.insert(mat[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    int isValid(vector<vector<int>> mat)
    {
        // code here
        if (!isRowVal(mat))
        {

            return false;
        }

        if (!isColVal(mat))
        {

            return false;
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                if (!checkBlock(mat, i, j))
                {
                    return false;
                }
            }
        }

        return true;
    }
};