#include <bits/stdc++.h>
using namespace std;
#define ll long long
void get_fraction(int nu, int de)
{
    if (nu % de == 0)
    {
        cout << nu / de << '\n';
        return;
    }
    if (de % nu == 0)
    {
        cout << 1 << '/' << de / nu << '\n';
        return;
    }
    int gcd = __gcd(nu, de);
    while (gcd != 1)
    {
        nu /= gcd;
        de /= gcd;
        gcd = __gcd(nu, de);
    }
    cout << nu << '/' << de << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nu, de;
    cin >> nu >> de;
    get_fraction(nu, de);
    return 0;
}