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
        string a;
        ll b;
        cin >> a >> b;
        ll ans = 0;
        if (a[0] == '-')
            a.erase(a.begin());
        b = abs(b);
        for (int i = 0; i < a.size(); i++)
        {
            ans = (1ll * ans * 10 % b + (a[i] - '0')) % b;
        }
        if (ans == 0)
            cout << "Case " << ++cs << ": " << "divisible" << '\n';
        else
            cout << "Case " << ++cs << ": " << "not divisible" << '\n';
    }
    return 0;
}