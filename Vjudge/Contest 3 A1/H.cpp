#include <bits/stdc++.h>
using namespace std;

bool makeBal(string &s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    if (makeBal(s))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}