#include <bits/stdc++.h>
using namespace std;

class Solution
{
    //Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && a[s.top()] < a[i])
            {
                s.pop();
            }

            s.push(i);
        }

        vector<int> res;
        while (!s.empty())
        {
            res.push_back(a[s.top()]);
            s.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
