#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int N)
{
    // Your code here
    vector<string> res;
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= N; i++)
    {
        res.push_back(q.front());
        q.push(q.front() + '0');
        q.push(q.front() + '1');
        q.pop();
    }

    return res;
}