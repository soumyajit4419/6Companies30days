#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        int start = 1;
        int end = 1000000000;

        while (start <= end)
        {
            int k = (start + end) / 2;
            int s = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                s += ceil((double)piles[i] / (double)k);
            }

            if (s > h)
            {
                start = k + 1;
            }
            else
            {
                end = k - 1;
            }
        }

        return start;
    }
};