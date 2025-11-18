#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    int cnt = 0, pos = a.find(b);
    while (pos != string::npos)
    {
        cnt++;
        pos = a.find(b, pos + 1);
    }
    cout << cnt << '\n';
    return 0;
}