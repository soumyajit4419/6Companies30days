#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void checkSubset(int arr[], int n, int target, vector<vector<bool>> &dp)
    {

        for (int i = 0; i <= n; i++)
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

        return;
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, 0));

        checkSubset(arr, n, target, dp);

        int res = INT_MAX;

        for (int i = 0; i <= target; i++)
        {
            if (dp[n][i])
            {
                res = min(res, sum - (2 * i));
            }
        }

        return res;
    }
};