#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    int *ans = new int[2];

    set<int> s;
    int duc = -1;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) != s.end())
        {
            duc = arr[i];
        }

        s.insert(arr[i]);
    }

    int miss = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) == s.end())
        {
            miss = i;
            break;
        }
    }
    ans[0] = duc;
    ans[1] = miss;
    return ans;
}