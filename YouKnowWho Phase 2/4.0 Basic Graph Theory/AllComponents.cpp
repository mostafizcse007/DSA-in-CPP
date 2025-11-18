#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N);
vector<vector<int>> com;
void dfs(int u, vector<int> &arr)
{
    vis[u] = true;
    arr.push_back(u);
    for (auto x : g[u])
    {
        if (!vis[x])
            dfs(x, arr);
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
    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            vector<int> arr;
            dfs(i, arr);
            com.push_back(arr);
        }
    }
    for (auto it : com)
    {
        for (auto x : it)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}