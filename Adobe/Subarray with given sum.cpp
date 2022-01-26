#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long target)
    {
        // Your code here

        long long int s = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            s += arr[i];

            while (s > target)
            {
                s -= arr[start];
                start++;
            }

            if (s == target)
            {
                return {start + 1, i + 1};
            }
        }

        return {-1};
    }
};