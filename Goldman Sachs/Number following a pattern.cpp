#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string printMinNumberForPattern(string s)
    {
        // code here
        stack<int> st;
        string res = "";
        for (int i = 0; i <= s.length(); i++)
        {
            st.push(i + 1);

            if (i == s.length() || s[i] == 'I')
            {

                while (!st.empty())
                {
                    int k = st.top();
                    st.pop();
                    res += to_string(k);
                }
            }
        }

        return res;
    }
};