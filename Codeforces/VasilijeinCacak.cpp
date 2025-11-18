#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 9;
vector<ll> ps(N);
void precompute()
{
    ps[0] = 0;
    for (int i = 1; i < N; i++)
        ps[i] += i + ps[i - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        ll x;
        cin >> n >> k >> x;
        ll max_sum = ps[n] - ps[n - k];
        ll min_sum = ps[k];
        if (x >= min_sum && x <= max_sum)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}