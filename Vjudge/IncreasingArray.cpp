#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            cnt += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    cout << cnt << '\n';
    return 0;
}