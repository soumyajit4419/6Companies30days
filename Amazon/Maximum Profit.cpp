#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMax(int A[], int N, int maxTransactions, bool bought, int pos, vector<vector<vector<int>>> &mem)
    {
        if (pos >= N || maxTransactions == 0)
        {
            return 0;
        }

        if (mem[bought][maxTransactions][pos] != -1)
        {
            return mem[bought][maxTransactions][pos];
        }

        int res = findMax(A, N, maxTransactions, bought, pos + 1, mem); //skip

        if (bought)
        {
            res = max(res, findMax(A, N, maxTransactions - 1, false, pos + 1, mem) + A[pos]); //sell
        }
        else
        {
            res = max(res, findMax(A, N, maxTransactions, true, pos + 1, mem) - A[pos]); //buy
        }
        mem[bought][maxTransactions][pos] = res;
        return res;
    }

    int maxProfit(int K, int N, int A[])
    {
        // code here
        vector<vector<vector<int>>> mem(2, vector<vector<int>>(K + 1, vector<int>(N, -1)));
        return findMax(A, N, K, false, 0, mem);
    }
};