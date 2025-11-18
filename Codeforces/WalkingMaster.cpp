#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll min_move(int cx, int cy, int dx, int dy)
{
    if (cy > dy)
        return -1;
    ll move = 0;
    move += (dy - cy);
    cx += (dy - cy);
    if (cx < dx)
        return -1;
    move += (cx - dx);
    return move;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int cx, cy, dx, dy;
        cin >> cx >> cy >> dx >> dy;
        cout << 1ll * min_move(cx, cy, dx, dy) << '\n';
    }
    return 0;
}