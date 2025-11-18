#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto st = clock();
    ll n;
    cin >> n;
    ll maxi = -1;
    ll x = sqrtl(n);
    while (x * x < n)
        ++x;
    while (x * x > n)
        --x;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            maxi = max(maxi, i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        maxi = max(maxi, x);
    cout << maxi << endl;
    cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
    return 0;
}