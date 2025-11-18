#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_possible(ll n, ll k)
{
    if (n % k == 0 or n % 2 == 0)
        return true;
    if ((n - 2) % k == 0)
        return true;
    if ((n - k) % 2 == 0)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (is_possible(n, k))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}