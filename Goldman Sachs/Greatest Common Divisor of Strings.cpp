#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {

        if (str1 + str2 == str2 + str1)
        {
            int gcd = __gcd(str1.length(), str2.length());
            return str1.substr(0, gcd);
        }

        return "";
    }
};