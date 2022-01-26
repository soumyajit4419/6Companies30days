#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> m;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        vector<string> res(2);
        int maxVal = 0;
        for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            int val = itr->second;
            if (val > maxVal)
            {
                res[0] = itr->first;
                res[1] = to_string(itr->second);
                maxVal = val;
            }
            else if (val == maxVal)
            {

                if (itr->first < res[0])
                {
                    res[0] = itr->first;
                    res[1] = to_string(itr->second);
                }
            }
        }

        return res;
    }
};