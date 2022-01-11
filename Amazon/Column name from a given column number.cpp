#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string colName(long long int n)
    {
        // your code here

        string res = "";
        while (n > 0)
        {
            long long int x = (n - 1) % 26;
            res = char(x + 65) + res;
            n--;
            n = n / 26;
        }

        return res;
    }
};