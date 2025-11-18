#include <bits/stdc++.h>
using namespace std;
int getCount(vector<char> &str)
{
    int cnt = 0;
    unordered_set<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.find(str[i]) == st.end())
            cnt += 2;
        else
            cnt += 1;
        st.insert(str[i]);
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> str(n);
        for (int i = 0; i < n; i++)
            cin >> str[i];
        cout << getCount(str) << endl;
    }
    return 0;
}