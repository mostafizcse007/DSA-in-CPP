#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll kThDiv(ll n, ll k)
{
    vector<ll> asc, dec;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            asc.push_back(i);
            if ((n / i) != i)
                dec.push_back(n / i);
        }
    }
    reverse(dec.begin(), dec.end());
    asc.insert(asc.end(), dec.begin(), dec.end());
    if (k > asc.size())
        return -1;
    ll ans = asc[k - 1];
    return ans;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = kThDiv(n, k);
    cout << ans << endl;
    return 0;
}