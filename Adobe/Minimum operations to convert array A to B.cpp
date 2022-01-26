#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lis(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 0;
        }

        vector<int> v;
        v.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > v[v.size() - 1])
            {
                v.push_back(arr[i]);
            }
            else
            {
                auto itr = lower_bound(v.begin(), v.end(), arr[i]);
                int idx = itr - v.begin();
                v[idx] = arr[i];
            }
        }

        return v.size();
    }

    int minInsAndDel(int a[], int b[], int n, int m)
    {
        // code here
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[b[i]]++;
        }

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) != mp.end())
            {
                v.push_back(a[i]);
            }
        }

        return (n + m) - 2 * lis(v);
    }
};