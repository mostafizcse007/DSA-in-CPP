#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
int dp[N];
int min_steps(int n)
{
    if (n == 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = min_steps(n - 1) + 1;
    if (n % 2 == 0)
        ans = min(ans, min_steps(n / 2) + 1);
    if (n % 3 == 0)
        ans = min(ans, min_steps(n / 3) + 1);
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
    cout << min_steps(n) << '\n';
    return 0;
}