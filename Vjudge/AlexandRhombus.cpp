#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll ans = n * n;
    ans *= 2;
    ans -= (2 * n);
    cout << ans + 1 << endl;
    return 0;
}