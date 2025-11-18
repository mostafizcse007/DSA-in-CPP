#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPossible(ll a, ll b)
{
    while (b != 1)
    {
        ll gcd = __gcd(a, b);
        if (gcd == 1)
            return false;
        b /= gcd;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (isPossible(a, b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}