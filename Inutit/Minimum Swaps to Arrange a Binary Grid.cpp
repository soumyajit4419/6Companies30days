#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        vector<int> numZeros(n, 0);

        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = m - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    break;
                }
                count++;
            }

            numZeros[i] = count;
        }

        int numSwap = 0;

        for (int i = 0; i < n; i++)
        {
            int zeroWanted = n - i - 1;
            if (numZeros[i] >= zeroWanted)
            {
                continue;
            }

            int j = i + 1;
            while (j < n && numZeros[j] < zeroWanted)
            {
                j++;
            }

            if (j == n)
            {
                return -1;
            }

            while (j > i)
            {
                swap(numZeros[j], numZeros[j - 1]);
                j--;
                numSwap++;
            }
        }

        return numSwap;
    }
};