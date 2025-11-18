#include <bits/stdc++.h>
using namespace std;
#define ll long long

int getRemainder(int x, int y, int n)
{
    int ans = n / x;
    if (((ans * x) + y) % x == y && ((ans * x) + y)<=n)
        return (ans * x) + y;
    --ans;
    return (ans * x) + y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        cin >> x >> y >> n;
        cout << getRemainder(x, y, n) << '\n';
    }
    return 0;
}