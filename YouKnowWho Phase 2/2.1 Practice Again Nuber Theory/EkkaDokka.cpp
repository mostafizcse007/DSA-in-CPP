#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n & 1)
            cout << "Case " << ++cs << ": " << "Impossible" << endl;
        else
        {
            for (ll i = 2; i <= n; i += 2)
            {
                if (n % i == 0 and ((n / i) & 1))
                {
                    cout << "Case " << ++cs << ": " << n / i << ' ' << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}