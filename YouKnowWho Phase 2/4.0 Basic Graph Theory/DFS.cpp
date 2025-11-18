#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N);
void dfs(int u, int &cnt)
{
    vis[u] = true;
    cnt++;
    for (auto x : g[u])
    {
        if (!vis[x])
            dfs(x, cnt);
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
    dfs(1, cnt);
    if (cnt == n)
        cout << "Connected" << '\n';
    else
        cout << "Disconnected" << '\n';
    return 0;
}