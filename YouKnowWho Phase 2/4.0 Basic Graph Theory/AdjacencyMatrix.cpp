#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 9;
int g[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto st = clock();
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    if (g[1][4])
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC;
    return 0;
}