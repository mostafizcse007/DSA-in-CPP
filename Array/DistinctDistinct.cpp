#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntDiv(ll n)
{
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    cout << cntDiv(n) << endl;
    return 0;
}