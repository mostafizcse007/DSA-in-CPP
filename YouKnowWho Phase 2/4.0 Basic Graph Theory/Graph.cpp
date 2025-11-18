#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(0));
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        int u, cnt;
        cin >> u >> cnt;
        maxi = max(maxi, cnt);
        while (cnt--)
        {
            int v;
            cin >> v;
            g[u].push_back(v);
        }
    }
    int final = max(n, maxi);
    int ans[final][final];
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++)
    {
        for (auto x : g[i])

        {
            if (x > 0)
                ans[i - 1][x - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
                cout << ' ';
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}