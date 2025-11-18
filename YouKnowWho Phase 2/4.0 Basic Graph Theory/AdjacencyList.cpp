#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 9;
set<int> st[N];
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
        st[u].insert(v);
        st[v].insert(u);
    }
    if (st[3].find(2) != st[3].end())
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}