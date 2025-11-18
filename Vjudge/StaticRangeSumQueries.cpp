#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == 1)
            cout << arr[r - 1] << '\n';
        else
            cout << arr[r - 1] - arr[l - 2] << '\n';
    }
    return 0;
}