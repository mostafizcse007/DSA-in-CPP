#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll gcd = 0;
    for (int i = 0; i < n; i++)
        gcd = __gcd(gcd, arr[i]);
    ll cnt = 0;
    for (ll i = 1; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            cnt++;
            if ((gcd / i) != i)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}