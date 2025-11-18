#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(vector<int> &arr)
{
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            cout << "YES\n"
                 << i << ' ' << i + 1 << ' ' << i + 2 << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr);
    }
    return 0;
}