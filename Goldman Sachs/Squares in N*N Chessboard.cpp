#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long squaresInChessBoard(long long N)
    {
        // code here
        long long int res = 0;
        for (long long int i = 1; i <= N; i++)
        {
            res += i * i;
        }

        return res;
    }
};