#include <bits/stdc++.h>
using namespace std;
bool pickWinner(string &str)
{
    int n = str.size();
    int del = 0;
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && st.top() == str[i])
        {
            st.pop();
            del++;
        }
        else
        {
            st.push(str[i]);
        }
    }
    if (del & 1)
        return 1;
    return 0;
}
int main()
{
    string str;
    cin >> str;
    if (pickWinner(str))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}