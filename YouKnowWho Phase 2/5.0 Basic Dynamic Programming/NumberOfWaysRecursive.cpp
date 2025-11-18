#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
vector<ll> dp(N, -1);
int count_ways(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = count_ways(n - 1) + count_ways(n - 3) % mod;
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << count_ways(n) << '\n';
    return 0;
}