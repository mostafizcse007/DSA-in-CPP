#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPossible(vector<ll> &arr, vector<ll> &brr)
{
    set<int> st1(arr.begin(), arr.end()), st2(brr.begin(), brr.end());
    if ((st1.size() >= 2 and st2.size() >= 2) or (st1.size() >= 3 and st2.size() >= 1) or (st1.size() >= 1 and st2.size() >= 3))
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n), brr(n);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        for (ll i = 0; i < n; i++)
            cin >> brr[i];
        if (isPossible(arr, brr))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}