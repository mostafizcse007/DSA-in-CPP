#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll multi(ll a, ll b, ll p)
{
    
    return (__int128)a * b % p;
}
ll bigMod(ll base, ll power, ll mod)
{
    ll ans = 1 % mod;
    while (power)
    {
        if (power & 1)
        {
            ans = multi(ans, base, mod);
        }
        base = multi(base, base, mod);
        power >>= 1;
    }
    return ans;
}
ll modInverse(ll a, ll p)
{
    return bigMod(a, p - 2, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, p;
    cin >> a >> b >> p;
    cout << bigMod(a, b, p) << ' ';
    cout << multi(a, b, p) << ' ';
    cout << multi(a, modInverse(b, p), p) << '\n';
    return 0;
}