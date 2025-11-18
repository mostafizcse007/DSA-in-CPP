#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 9;
vector<double> store(n);
#define ll long long
void precompute()
{
    for (int i = 1; i <= n; i++)
        store[i] = store[i - 1] + log10(i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n, base;
        cin >> n >> base;
        double total = store[n];
        total /= log10(base);
        total += 1;
        cout << "Case " << ++cs << ": " << (ll)floor(total) << '\n';
    }
    return 0;
}
