#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int maxInc = arr[0];
        int maxExc = 0;

        for (int i = 1; i < n; i++)
        {

            int temp = maxInc;

            maxInc = max(maxInc, maxExc + arr[i]);
            maxExc = temp;
        }

        return maxInc;
    }
};