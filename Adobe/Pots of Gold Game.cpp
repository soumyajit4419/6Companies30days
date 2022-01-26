#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int maxCoins(vector<int> &arr, int n)
    {
        //Write your code here

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

        for (int i = 0; i < n; i++)
        {
            dp[i][i].first = arr[i];
            dp[i][i].second = 0;
        }

        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i <= n - k; i++)
            {
                int lp = arr[i] + dp[i + 1][i + k - 1].second;
                int rp = arr[i + k - 1] + dp[i][i + k - 2].second;
                if (lp > rp)
                {
                    dp[i][i + k - 1].first = lp;
                    dp[i][i + k - 1].second = dp[i + 1][i + k - 1].first;
                }
                else
                {
                    dp[i][i + k - 1].first = rp;
                    dp[i][i + k - 1].second = dp[i][i + k - 2].first;
                }
            }
        }

        return dp[0][n - 1].first;
    }
};