#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> res;

    void generateParen(int open, int close, int n, string s)
    {

        if (open + close == 2 * n)
        {
            res.push_back(s);
            return;
        }

        if (open < n)
        {
            generateParen(open + 1, close, n, s + '(');
        }

        if (close < open)
        {
            generateParen(open, close + 1, n, s + ')');
        }

        return;
    }

    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        generateParen(0, 0, n, "");
        return res;
    }
};