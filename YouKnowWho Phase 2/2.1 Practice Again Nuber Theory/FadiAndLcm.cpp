#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> is_prime(ll n)
{
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (n % i != i)
                divs.push_back(n / i);
        }
    }
    return divs;
}
ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> divs = is_prime(n);
    ll ans1 = 1, ans2 = n;
    ll min_max = n;

    for (ll d : divs)
    {
        ll a = d;
        ll b = n / d;
        if (lcm(a, b) == n && max(a, b) < min_max)
        {
            min_max = max(a, b);
            ans1 = a;
            ans2 = b;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}
