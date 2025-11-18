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
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];

        int q;
        cin >> q;
        while (q--)
        {
            int left, right;
            cin >> left >> right;
            --left;
            --right;
            if (left == 0)
            {
                cout << arr[right] << '\n';
            }
            else
            {
                cout << arr[right] - arr[left - 1] << '\n';
            }
        }
        return 0;
    }
}