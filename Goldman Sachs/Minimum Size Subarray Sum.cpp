#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int sum = 0;
        int start = 0;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            while (sum >= target)
            {
                int dif = (i - start) + 1;
                res = min(res, dif);
                sum -= nums[start];
                start++;
            }
        }

        if (res == INT_MAX)
        {
            return 0;
        }

        return res;
    }
};
