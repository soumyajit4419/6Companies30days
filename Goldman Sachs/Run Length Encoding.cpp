#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{
    //Your code here
    int count = 1;
    char prev = src[0];

    string res = "";

    for (int i = 1; i < src.length(); i++)
    {
        if (src[i] == prev)
        {
            count++;
        }
        else
        {
            res += prev + to_string(count);
            prev = src[i];
            count = 1;
        }
    }

    res += prev + to_string(count);
    return res;
}