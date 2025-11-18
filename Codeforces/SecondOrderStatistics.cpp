#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    sort(arr.rbegin(), arr.rend());
    int ch1 = arr[k - 1].first, ch2 = arr[k - 1].second;
    int cnt = 0;
    // for (auto x : arr)
    // {
    //     if (x.first == ch1 and x.second == ch2)
    //         cnt++;
    // }
    // cout << cnt << '\n';
    for (auto x : arr)
        cout << x.first << ' ' << x.second << '\n';
    return 0;
}