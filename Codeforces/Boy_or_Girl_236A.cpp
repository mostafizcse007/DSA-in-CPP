#include <bits/stdc++.h>
using namespace std;
int distinct(string &s)
{
    int count = 0;
    unordered_set<char> st(s.begin(), s.end());
    return st.size();
}
int main()
{
    string s;
    cin >> s;
    int res = distinct(s);
    if (res & 1)
        cout << "IGNORE HIM!" << endl;
    else
        cout << "CHAT WITH HER!" << endl;
    return 0;
}