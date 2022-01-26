#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findMax(string &str, int k, string &maxRes)
    {
        if (k == 0)
        {
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {

            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[j] > str[i])
                {
                    swap(str[j], str[i]);
                    maxRes = max(maxRes, str);
                    findMax(str, k - 1, maxRes);
                    swap(str[j], str[i]);
                }
            }
        }

        return;
    }

    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // code here.
        string maxRes = str;
        findMax(str, k, maxRes);
        return maxRes;
    }
};

class Solution
{
public:
    void findMax(string str, int k, string &maxRes, int pos)
    {
        if (k == 0)
        {
            return;
        }

        char maxCr = str[pos];

        for (int j = pos + 1; j < str.length(); j++)
        {
            if (str[j] > maxCr)
            {
                maxCr = str[j];
            }
        }

        if (maxCr != str[pos])
            --k;

        for (int j = str.length() - 1; j >= pos; j--)
        {
            if (str[j] == maxCr)
            {
                swap(str[pos], str[j]);
                maxRes = max(maxRes, str);
                findMax(str, k, maxRes, pos + 1);
                swap(str[pos], str[j]);
            }
        }

        return;
    }

    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // code here.
        string maxRes = str;
        findMax(str, k, maxRes, 0);
        return maxRes;
    }
};