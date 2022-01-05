// recursion TLE
#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int md = 1000000000 + 7;
    unordered_map<string, int> m;

    int count(string s)
    {

        if (m.find(s) != m.end())
        {
            return m[s];
        }

        if (s == "")
        {
            return 1;
        }

        int c1 = 0, c2 = 0;
        int x = s[0] - 48;

        if (x >= 1 && x <= 26)
        {
            c1 = count(s.substr(1));
        }

        if (s.length() > 1)
        {
            int y = ((s[0] - 48) * 10) + (s[1] - 48);

            if (y >= 10 && y <= 26)
            {
                c2 = count(s.substr(2));
            }
        }

        int res = ((c1 % md) + (c2 % md)) % md;
        m[s] = res;
        return res;
    }

    int CountWays(string str)
    {

        return count(str);
    }
};
