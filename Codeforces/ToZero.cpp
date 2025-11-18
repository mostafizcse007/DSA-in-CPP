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
        ll n, k;
        cin >> n >> k;
        if (n & 1)
        {
            if (n % k != 0)
                cout << 2 + ((n - k) / (k - 1)) << '\n';
            else
                cout << 1 + ((n - k) / (k - 1)) << '\n';
        }

        else
        {
            int ans = n / (k - 1);
            if (n % (k - 1) == 0)
                cout << ans << '\n';
            else
                cout << ++ans << '\n';
        }
    }
    return 0;
}