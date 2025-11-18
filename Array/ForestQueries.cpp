#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    vector<vector<int>> pf(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
            if (arr[i - 1][j - 1] == '*')
                pf[i][j]++;
        }
    }
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << pf[y2][x2] - pf[y1 - 1][x2] - pf[y2][x1 - 1] + pf[y1 - 1][x1 - 1] << '\n';
    }
    return 0;
}