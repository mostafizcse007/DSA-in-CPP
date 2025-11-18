#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll gcd = __gcd(n, m);
    if ((n / gcd) > (r / m))
    {
        cout << 0 << '\n';
        return 0;
    }
    ll lcm = (n * m) / gcd;
    ll total = (r / lcm) - ((l - 1) / lcm);
    cout << total << '\n';
    return 0;
}