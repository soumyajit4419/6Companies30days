#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {

        deque<int> q;
        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && arr[i] > arr[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        for (int i = 0; i <= n - k; i++)
        {
            res.push_back(arr[q.front()]);

            while (!q.empty() && q.front() <= i)
            {
                q.pop_front();
            }

            if (i + k < n)
            {
                while (!q.empty() && arr[i + k] > arr[q.back()])
                {
                    q.pop_back();
                }

                q.push_back(i + k);
            }
        }

        return res;
    }
};
