#include <bits/stdc++.h>
using namespace std;
string charFind(vector<char> &st1, vector<char> &st2, vector<char> &st3)
{
    vector<char> st4 = st1;
    st4.insert(st4.end(), st2.begin(), st2.end());
    sort(st4.begin(), st4.end());
    sort(st3.begin(), st3.end());
    if (st4.size() != st3.size())
        return "NO";
    for (int i = 0; i < st4.size(); i++)
        if (st4[i] != st3[i])
            return "NO";
    return "YES";
}
int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    vector<char> st1(a.begin(), a.end());
    vector<char> st2(b.begin(), b.end());
    vector<char> st3(c.begin(), c.end());
    cout << charFind(st1, st2, st3) << endl;
    return 0;
}