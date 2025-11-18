#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << arr[0] << ' ';

    for (int i = 1; i < n; i++)
        cout << arr[i] - arr[i - 1] << ' ';

    return 0;
}