#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll val = 10e17, ans = 1;
    ll mini = *min_element(arr.begin(), arr.end());
    if (mini == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    for (ll i = 0; i < n; i++)
    {
        if (ans <= (val / arr[i]))
            ans = ans * arr[i];
        else
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}