#include <bits/stdc++.h>
using namespace std;

// recursion TLE
class Solution
{
public:
    int count(int target, int pos, int steps)
    {

        if (abs(pos) > target)
        {
            return INT_MAX;
        }

        if (pos == target)
        {
            return steps;
        }

        int fd = count(target, pos + steps, steps + 1);
        int bk = count(target, pos - steps, steps + 1);

        return min(fd, bk);
    }

    int minSteps(int D)
    {
        // code here
        return count(D, 0, 1) - 1;
    }
};

class Solution
{
public:
    int minSteps(int D)
    {
        // code here

        int target = abs(D);
        int i = 0;

        int steps = 0;

        while (i < target || (i - target) % 2 != 0)
        {
            steps++;
            i += steps;
        }

        return steps;
    }
};