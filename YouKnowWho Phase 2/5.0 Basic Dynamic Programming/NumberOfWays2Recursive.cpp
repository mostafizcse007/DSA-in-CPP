#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 9, mod = 1e9 + 7;
ll dp[N];
ll count_ways(int n)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += count_ways(n - i);
        ans %= mod;
    }
    dp[n] = ans;
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << count_ways(n) << '\n';
    return 0;
}