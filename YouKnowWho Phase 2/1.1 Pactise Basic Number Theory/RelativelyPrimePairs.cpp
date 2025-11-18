#include <bits/stdc++.h>
using namespace std;
#define ll long long
void Solve(ll l, ll r)
{
    if (l == 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (ll i = l; i < r; i += 2)
    {
        cout << i << " " << i + 1 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l, r;
    cin >> l >> r;
    Solve(l, r);
    return 0;
}