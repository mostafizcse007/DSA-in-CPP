#include <bits/stdc++.h>
using namespace std;
string modifyString(string &a, string &b)
{
    string ans;
    for (int i = 0; i < a.size(); i++)
    {
        if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
            ans += '1';
        else if (a[i] == '0' && b[i] == '0')
            ans += '0';
        else if (a[i] == '1' && b[i] == '1')
            ans += '0';
    }
    return ans;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << modifyString(a, b) << endl;
    return 0;
}