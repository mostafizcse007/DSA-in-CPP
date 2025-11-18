#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXB = 1000;
    const int INF = 1e9;
    vector<int> dist(MAXB + 1, INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        int d = dist[v];
        for (int x = 1; x <= v; ++x)
        {
            int inc = v / x;
            int nv = v + inc;
            if (nv > MAXB)
                continue;
            if (dist[nv] > d + 1)
            {
                dist[nv] = d + 1;
                q.push(nv);
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        for (int i = 0; i < n; ++i)
            cin >> c[i];

        long long baseCoins = 0;
        vector<pair<int, int>> items;
        for (int i = 0; i < n; ++i)
        {
            int w = (b[i] <= MAXB ? dist[b[i]] : INF);
            if (w == INF || w > k)
                continue;
            if (w == 0)
            {
                baseCoins += c[i];
            }
            else
            {
                items.emplace_back(w, c[i]);
            }
        }

        long long sumOps = 0, sumCoins = 0;
        for (auto &p : items)
        {
            sumOps += p.first;
            sumCoins += p.second;
        }
        long long answer = baseCoins;
        if (sumOps <= k)
        {
            answer += sumCoins;
            cout << answer << "\n";
            continue;
        }
        int cap = k;
        vector<long long> dp(cap + 1, 0);
        for (auto &p : items)
        {
            int w = p.first;
            int val = p.second;
            for (int j = cap; j >= w; --j)
            {
                dp[j] = max(dp[j], dp[j - w] + val);
            }
        }
        long long best = 0;
        for (int j = 0; j <= cap; ++j)
            best = max(best, dp[j]);

        answer += best;
        cout << answer << "\n";
    }

    return 0;
}
