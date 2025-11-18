#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    prefix[0][0] = arr[0][0];
    for (int i = 1; i < m; i++)
        prefix[0][i] = prefix[0][i - 1] + arr[0][i];
    for (int i = 1; i < n; i++)
        prefix[i][0] = prefix[i - 1][0] + arr[i][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << prefix[i][j] << " ";
        cout << endl;
    }
    return 0;
}