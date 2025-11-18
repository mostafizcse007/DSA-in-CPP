#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<int> par(N), dis(N);
vector<bool> vis(N);
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
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    vis[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto x : g[u])
        {
            if (!vis[x])
            {
                vis[x] = true;
                dis[x] = dis[u] + 1;
                par[x] = u;
                q.push(x);
            }
        }
    }
    int dest;
    cin >> dest;
    while (dest != 1)
    {
        cout << dest << ' ';
        dest = par[dest];
    }
    cout << 1 << '\n';
    return 0;
}