#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int max_member(int c, int m, int x)
{
    ll n = c + m + x;
    int low = 0, high = (n / 3) + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (c >= mid && m >= mid && 3 * mid <= n)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low - 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int c, m, x;
        cin >> c >> m >> x;
        cout << max_member(c, m, x) << '\n';
    }
    return 0;
}