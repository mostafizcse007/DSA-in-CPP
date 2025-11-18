#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 9;
vector<int> g[N];
bool vis[N];
int indeg[N];
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
        indeg[v]++;
    }
    vector<int> ans;
    while (ans.size() < n)
    {
        int cur = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] and indeg[i] == 0)
            {
                cur = i;
                break;
            }
        }
        if (cur == 0)
        {
            cout << "Impossible" << '\n';
            return 0;
        }
        vis[cur] = true;
        ans.push_back(cur);
        for (auto x : g[cur])
            indeg[x]--;
    }
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}