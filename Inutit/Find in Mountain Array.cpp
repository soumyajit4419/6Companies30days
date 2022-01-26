#include <bits/stdc++.h>
using namespace std;
class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findPeakIndex(int start, int end, MountainArray &mountainArr)
    {

        while (start <= end)
        {

            int mid = (start + end) / 2;

            if (mountainArr.get(mid + 1) > mountainArr.get(mid))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return start;
    }

    int find(int start, int end, MountainArray &mountainArr, bool isIncrease, int target)
    {

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else
            {
                if (mountainArr.get(mid) > target)
                {
                    if (isIncrease)
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
                else
                {
                    if (isIncrease)
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr)
    {

        int start = 0;
        int end = mountainArr.length() - 1;

        int pi = findPeakIndex(start, end, mountainArr);

        int idx = find(0, pi, mountainArr, true, target);

        if (idx == -1)
        {
            idx = find(pi + 1, end, mountainArr, false, target);
        }

        return idx;
    }
};