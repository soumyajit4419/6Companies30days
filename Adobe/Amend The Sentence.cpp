#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string amendSentence(string s)
    {

        // your code here
        string res = "";
        int i = 0;

        while (i < s.length())
        {
            string word = "";
            if (s[i] >= 65 && s[i] <= 90)
            {
                word += (s[i] - 65) + 97;
                i++;
            }
            else
            {
                word += s[i];
                i++;
            }

            while (i < s.length() && s[i] >= 97 && s[i] <= 122)
            {
                word += s[i];
                i++;
            }

            res = res + word + ' ';
        }

        res.pop_back();
        return res;
    }
};