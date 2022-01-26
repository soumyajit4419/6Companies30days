#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int res = 0;
        int k = 0;
        bool neg = false;

        if (str[0] == '-')
        {
            neg = true;
            k++;
        }

        for (int i = k; i < str.length(); i++)
        {
            if (str[i] < 48 || str[i] > 57)
            {
                return -1;
            }

            res = res * 10 + (str[i] - 48);
        }

        if (neg)
        {
            return -res;
        }

        return res;
    }
};