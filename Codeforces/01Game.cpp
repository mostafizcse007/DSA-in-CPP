#include <bits/stdc++.h>
using namespace std;
#define ll long long
int max_pair(string &str)
{
    int n = str.size();
    if (n == 1)
        return 0;
    stack<char> st;
    st.push(str[0]);
    int cnt = 0, i = 1;
    while (i < n)
    {
        char front = st.top();
        while (!st.empty() && front != str[i] && i < n)
        {
            st.pop();
            i++;
            cnt++;
        }
        if (!st.empty() && front == str[i] && i < n)
        {
            st.push(str[i]);
            i++;
        }
        if (st.empty())
        {
            st.push(str[i]);
            i++;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (max_pair(str) & 1)
            cout << "DA" << '\n';
        else
            cout << "NET" << '\n';
    }
    return 0;
}