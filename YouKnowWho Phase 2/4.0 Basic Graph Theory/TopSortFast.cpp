#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
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
    vector<int> zero;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            zero.push_back(i);
    }
    vector<int> ans;
    while (ans.size() < n)
    {
        if (zero.empty())
        {
            cout << "Impossible" << '\n';
            return 0;
        }
        int cur = zero.back();
        zero.pop_back();
        ans.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if (!vis[v] and indeg[v] == 0)
            {
                zero.push_back(v);
                vis[v] = true;
            }
        }
    }
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}