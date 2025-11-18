#include <bits/stdc++.h>
using namespace std;
#define ll long long
int fact_pow(int n, int p)
{
    int ans = 0;
    while (n)
    {
        n /= p;
        ans += n;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << fact_pow(n, k) << '\n';
    return 0;
}