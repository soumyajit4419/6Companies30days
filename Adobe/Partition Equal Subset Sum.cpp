#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPartition(int arr[], int n, int target)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            int val = arr[i - 1];
            for (int j = 1; j <= target; j++)
            {
                if (val <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - val];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }

    int equalPartition(int n, int arr[])
    {
        // code here
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += arr[i];
        }

        if (s % 2 != 0)
        {
            return 0;
        }

        int target = s / 2;

        if (checkPartition(arr, n, target))
        {
            return 1;
        }

        return 0;
    }
};