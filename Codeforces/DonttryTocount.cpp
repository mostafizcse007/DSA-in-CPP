#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, cnt = 0;
        cin >> a >> b;
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            cout << 0 << '\n';
            continue;
        }
        while (a < b)
        {
            a += s1.size();
            s1 += s1;
            cnt++;
        }
        int val = s1.find(s2);
        if (val != string::npos)
        {
            cout << cnt << '\n';
            continue;
        }
        s1 += s1;
        cnt++;
        int x = s1.find(s2);
        if (x != string::npos)
            cout << cnt << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}