#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    string FirstNonRepeating(string s)
    {
        // Code here
        queue<char> q;
        unordered_map<char, int> m;

        string res = "";
        for (int i = 0; i < s.length(); i++)
        {

            m[s[i]]++;

            if (m[s[i]] == 1)
            {
                q.push(s[i]);
            }

            while (!q.empty() && m[q.front()] != 1)
            {
                q.pop();
            }

            if (!q.empty())
            {
                res += q.front();
            }
            else
            {
                res += '#';
            }
        }

        return res;
    }
};