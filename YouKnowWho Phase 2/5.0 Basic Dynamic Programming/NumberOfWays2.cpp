#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll count_ways(int n)
{
    if (n == 0)
        return 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += count_ways(n - i);
    }
    return ans;
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