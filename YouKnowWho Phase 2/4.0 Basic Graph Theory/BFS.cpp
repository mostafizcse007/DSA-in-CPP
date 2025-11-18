#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N], dis(N);
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
    vis[1] = true;
    dis[1] = 0;
    while (!q.empty())
    {
        
        int u = q.front();
        q.pop();
        for (auto x : g[u])
        {
            if (!vis[x])
            {
                dis[x] = dis[u] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}