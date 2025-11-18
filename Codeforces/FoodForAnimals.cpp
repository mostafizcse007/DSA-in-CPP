#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_possible(int a, int b, int c, int x, int y)
{
    if (a >= x && b >= y)
        return 1;
    ll total_need = x + y, total_have = a + b + c;
    if (total_need > total_have)
        return 0;
    ll for_dog = 0, for_cat = 0;
    if (a < x)
    {
        for_dog = a + (x - a);
        c -= (x - a);
    }
    if (b < y)
    {
        for_cat = b + (y - b);
        c -= (y - b);
    }
    if (c < 0)
        return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        if (is_possible(a, b, c, x, y))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}