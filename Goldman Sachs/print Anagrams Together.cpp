#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &sl)
    {
        //code here
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for (int i = 0; i < sl.size(); i++)
        {
            string k = sl[i];
            sort(k.begin(), k.end());
            m[k].push_back(sl[i]);
        }

        for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            res.push_back(itr->second);
        }

        return res;
    }
};