#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 9;
ll fast_expo(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll val = fast_expo(a, b / 2);
    ll result = (val * val);
    if (b & 1)
        result = (result * a);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;
    cout << fast_expo(a, b) + fast_expo(b, a);
    return 0;
}