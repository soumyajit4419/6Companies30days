#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        //code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pair<int, int> res;

        int maxVal = INT_MIN;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
            maxVal = max(maxVal, arr[i][0]);
        }

        int dif = maxVal - pq.top().first;
        res = {pq.top().first, maxVal};

        while (!pq.empty())
        {
            int minVal = pq.top().first;
            int minrow = pq.top().second.first;
            int minIdx = pq.top().second.second;

            if (minIdx + 1 < n)
            {
                pq.pop();
                pq.push({arr[minrow][minIdx + 1], {minrow, minIdx + 1}});
                maxVal = max(maxVal, arr[minrow][minIdx + 1]);
            }
            else
            {
                break;
            }

            int newdif = maxVal - pq.top().first;
            if (newdif < dif)
            {
                res = {pq.top().first, maxVal};
                dif = newdif;
            }
        }

        return res;
    }
};