#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        vector<int> res(n);
        res[0] = 1;
        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; i++)
        {
            while (!s.empty() && price[s.top()] <= price[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                res[i] = i - s.top();
            }
            else
            {
                res[i] = i - (-1);
            }

            s.push(i);
        }

        return res;
    }
};