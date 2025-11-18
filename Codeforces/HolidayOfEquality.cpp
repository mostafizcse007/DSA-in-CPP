#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int maxi = -1;
    for (auto it : arr)
        maxi = max(maxi, it);
    ll sum = 0;
    for (auto it : arr)
        sum += (maxi - it);
    cout << sum << '\n';
    return 0;
}