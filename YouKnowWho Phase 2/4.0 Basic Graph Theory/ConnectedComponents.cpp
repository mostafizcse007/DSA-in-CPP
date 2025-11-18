#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N);
void dfs(int u)
{
    vis[u] = true;
    for (auto x : g[u])
    {
        if (!vis[x])
            dfs(x);
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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt << '\n';
    return 0;
}