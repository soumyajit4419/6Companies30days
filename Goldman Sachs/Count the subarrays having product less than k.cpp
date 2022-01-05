#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {

        long long int prod = 1;

        int start = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            prod = prod * a[i];

            while (prod >= k)
            {
                prod = prod / a[start];
                start++;
            }

            count += (i - start) + 1;
        }

        return count;
    }
};