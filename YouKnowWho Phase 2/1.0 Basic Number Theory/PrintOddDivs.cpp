#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> oddDivs;
    for (ll i = 1; i * i <= n; i++)
        oddDivs.push_back(i * i);
    for (auto x : oddDivs)
        cout << x << " ";
    return 0;
}