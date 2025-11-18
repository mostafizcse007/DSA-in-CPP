#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_steps(int n)
{
    // Using dynamic programming with memoization
    static vector<int> memo(n + 1, -1);

    if (n == 1)
        return 0;

    // If we've already calculated this value, return it
    if (memo[n] != -1)
        return memo[n];

    int ans = min_steps(n - 1) + 1; // Missing semicolon fixed
    if (n % 2 == 0)
        ans = min(ans, min_steps(n / 2) + 1);
    if (n % 3 == 0)
        ans = min(ans, min_steps(n / 3) + 1);

    // Store the result before returning
    memo[n] = ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << min_steps(10) << '\n';
    return 0;
}