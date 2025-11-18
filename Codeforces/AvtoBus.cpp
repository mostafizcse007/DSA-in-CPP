#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n)
{
    if (n < 4 || (n & 1))
    {
        cout << -1 << endl;
        return;
    }

    if (n % 4 == 0 && n % 6 == 0)
        cout << n / 6 << ' ' << n / 4 << endl;
    else if (n % 6 == 0)
        cout << n / 6 << ' ' << n / 4 << endl;
    else
    {
        ll mini = (n / 6) + 1;
        ll maxi = n / 4;
        cout << mini << ' ' << maxi << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}