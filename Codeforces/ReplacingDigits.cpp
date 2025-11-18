#include <bits/stdc++.h>
using namespace std;
string maxA(string &a, string &b)
{
    sort(b.rbegin(), b.rend());
    int i = 0, j = 0, n = a.size(), m = b.size();
    while (i < n && j < m)
    {
        if (b[j] > a[i])
        {
            a[i] = b[j];
            j++;
        }
        i++;
    }
    return a;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << maxA(a, b) << endl;
    return 0;
}