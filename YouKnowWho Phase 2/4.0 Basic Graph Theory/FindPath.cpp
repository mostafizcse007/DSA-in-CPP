#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N);
vector<int> com(N, 0);
void dfs(int u, int cid)
{
    vis[u] = true;
    com[u] = cid;
    for (auto x : g[u])
    {
        if (!vis[x])
            dfs(x, cid);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, i);
    }
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (com[u] == com[v])
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}