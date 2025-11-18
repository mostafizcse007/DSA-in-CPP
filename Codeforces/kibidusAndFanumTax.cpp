#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

bool isPossible(vector<int> &arr, int b)
{
    int prev = min(arr[0], b - arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        int transformed = min(arr[i], b - arr[i]);

        if (transformed < prev)
            return false;

        prev = transformed;
    }
    return true;
}

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int b;
        cin >> b;

        if (isPossible(arr, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
