#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        // code here
        set<ull> s;
        s.insert(1);

        for (int i = 0; i < n - 1; i++)
        {
            ull num = *s.begin();
            s.erase(s.begin());
            s.insert(num * 2);
            s.insert(num * 3);
            s.insert(num * 5);
        }

        return *s.begin();
    }
};