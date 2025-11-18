#include <bits/stdc++.h>
using namespace std;
#define ll long long
int bigMod(int base, int power, int mod)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ((ans % mod) * (base % mod)) % mod;
        base = ((base % mod) * (base % mod)) % mod;
        power >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b, p, m;
    while (cin >> b >> p >> m)
    {
        cout << bigMod(b, p, m) << endl;
    }
    return 0;
}