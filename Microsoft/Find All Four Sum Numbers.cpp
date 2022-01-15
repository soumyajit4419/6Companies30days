#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int n = arr.size();
        int i = 0;

        while (i < n)
        {
            int s = k - arr[i];

            int j = i + 1;

            while (j < n)
            {

                int target = s - arr[j];

                int f = j + 1;
                int b = n - 1;

                while (f < b)
                {
                    if (arr[f] + arr[b] == target)
                    {
                        res.push_back({arr[i], arr[j], arr[f], arr[b]});
                        int t1 = arr[f];
                        int t2 = arr[b];
                        while (f < b && arr[f] == t1)
                        {
                            f++;
                        }

                        while (b > f && arr[b] == t2)
                        {
                            b--;
                        }
                    }
                    else if (arr[f] + arr[b] - target > 0)
                    {
                        b--;
                    }
                    else
                    {
                        f++;
                    }
                }

                while (j + 1 < n && arr[j] == arr[j + 1])
                {
                    j++;
                }
                j++;
            }

            while (i + 1 < n && arr[i] == arr[i + 1])
            {
                i++;
            }
            i++;
        }

        return res;
    }
};