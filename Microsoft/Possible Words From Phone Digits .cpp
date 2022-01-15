#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> res;
    void findCombinations(int a[], vector<string> &v, int n, int pos, string &s)
    {
        if (pos >= n)
        {
            res.push_back(s);
            return;
        }
        int num = a[pos];
        for (int i = 0; i < v[num].length(); i++)
        {
            s += v[num][i];
            findCombinations(a, v, n, pos + 1, s);
            s.pop_back();
        }
        return;
    }

    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string> v(10, "");
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";

        string s = "";
        findCombinations(a, v, n, 0, s);

        return res;
    }
};
