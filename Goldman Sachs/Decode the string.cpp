#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodedString(string s)
    {
        stack<char> st;

        string res = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {
                string k = "";
                while (!st.empty() && st.top() != '[')
                {
                    k = st.top() + k;
                    st.pop();
                }

                st.pop();

                string num = "";
                while (!st.empty() && st.top() >= 48 && st.top() <= 57)
                {
                    num = st.top() + num;
                    st.pop();
                }

                int n = stoi(num);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < k.length(); j++)
                    {
                        st.push(k[j]);
                    }
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};