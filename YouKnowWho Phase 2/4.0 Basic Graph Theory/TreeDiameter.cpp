#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<int> dep(N);
int maxi = -1, node = -1;
void dfs1(int u, int p)
{
    dep[u] = dep[p] + 1;
    if (dep[u] > maxi)
    {
        maxi = dep[u];
        node = u;
    }
    for (auto v : g[u])
    {
        if (v != p)
            dfs1(v, u);
    }
}
void dfs2(int u, int p)
{
    dep[u] = dep[p] + 1;
    maxi = max(maxi, dep[u]);
    for (auto v : g[u])
    {
        if (v != p)
            dfs2(v, u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[0] = -1;
    maxi = -1;
    dfs1(1, 0);
    dep.assign(N, 0);
    dfs2(node, 0);
    cout << maxi << '\n';
    return 0;
}