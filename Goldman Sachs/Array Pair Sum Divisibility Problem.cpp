#include <bits/stdc++.h>
using namespace std;

// Two sum with remainder
class solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.

        int n = nums.size();

        if (n % 2 != 0)
        {
            return false;
        }

        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            int rem = nums[i] % k;

            if (rem == 0)
            {
                if (m.find(0) != m.end() && m[0] > 0)
                {
                    count++;
                    m[0]--;
                    m[0]--;
                }
            }
            else
            {
                int val = k - rem;

                if (m.find(val) != m.end() && m[val] > 0)
                {
                    count++;
                    m[rem]--;
                    m[val]--;
                }
            }
            m[rem]++;
        }

        if (count == n / 2)
        {
            return true;
        }

        return false;
    }
};