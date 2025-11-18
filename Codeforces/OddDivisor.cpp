#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check_divs(ll n)
{
    int cnt = 0;
    while (n)
    {
        if (n & 1)
            cnt++;
        n >>= 1;
    }
    if (cnt == 1)
        return 1;
    return 0;
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
        if (check_divs(n))
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}