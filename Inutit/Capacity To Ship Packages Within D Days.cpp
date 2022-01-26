#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {

        int start = 1;
        int end = 1000000;

        while (start <= end)
        {
            int k = (start + end) / 2;

            int maxWeight = k;
            int numDays = 1;

            int j = 0;
            int s = 0;

            while (j < weights.size())
            {
                if (weights[j] + s <= maxWeight)
                {
                    s = s + weights[j];
                    j++;
                }
                else
                {
                    s = 0;
                    numDays++;
                }

                if (j < weights.size() && weights[j] > maxWeight)
                {
                    numDays = days + 1;
                    break;
                }
            }

            if (numDays > days)
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