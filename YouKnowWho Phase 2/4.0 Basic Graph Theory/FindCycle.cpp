#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> g[N];
int col[N];
bool cycle = false;
void dfs(int u)
{
    col[u] = 1;
    for (auto x : g[u])
    {
        if (col[x] == 0)
            dfs(x);
        else if (col[x] == 1)
            cycle = true;
    }
    col[u] = 2;
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
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
            dfs(i);
    }
    if (cycle)
        cout << "Cycle found" << '\n';
    else
        cout << "Cycle not found" << '\n';
    return 0;
}