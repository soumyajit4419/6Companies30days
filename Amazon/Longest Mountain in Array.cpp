#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {

        int i = 0;
        int n = arr.size();
        int res = 0;

        while (i < n)
        {

            int end = i;
            if (end + 1 < n && arr[end] < arr[end + 1])
            {
                while (end + 1 < n && arr[end] < arr[end + 1])
                {
                    end++;
                }

                if (end + 1 < n && arr[end] > arr[end + 1])
                {
                    while (end + 1 < n && arr[end] > arr[end + 1])
                    {
                        end++;
                    }
                    res = max(res, (end - i) + 1);
                }
            }
            i = max(end, i + 1);
        }

        return res;
    }
};