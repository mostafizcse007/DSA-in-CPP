#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
int dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int ans = 1 + dp[i - 1];
        if (i % 2 == 0)
            ans = min(ans, dp[i / 2] + 1);
        if (i % 3 == 0)
            ans = min(ans, dp[i / 3] + 1);
        dp[i] = ans;
    }
    cout << dp[n] << '\n';
    return 0;
}