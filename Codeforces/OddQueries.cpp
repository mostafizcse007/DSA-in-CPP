#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n + 1);
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int val = (r - l + 1) * k;
            int r_sum = arr[r] - arr[l - 1];
            int extra = val - r_sum;
            if ((arr[n] + extra) & 1)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}