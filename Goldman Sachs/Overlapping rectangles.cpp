#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[])
    {
        // code here

        //if one rectange is left of other
        if (l2[0] > r1[0] || l1[0] > r2[0])
        {
            return 0;
        }

        // if one rectange is top of other
        if (r2[1] > l1[1] || r1[1] > l2[1])
        {
            return 0;
        }

        return 1;
    }
};