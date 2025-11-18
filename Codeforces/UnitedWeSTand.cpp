#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(vector<int> &arr)
{
    int size = arr.size();
    if (size == 1)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> a1, b1;
    int maxi = *max_element(arr.begin(), arr.end());
    int cnt_max = 0;
    for (auto x : arr)
    {
        if (x == maxi)
            b1.push_back(x);
        else
            a1.push_back(x);
    }
    int x1 = a1.size(), x2 = b1.size();
    if (x1 and x2)
    {
        cout << x1 << ' ' << x2 << '\n';
        for (auto x : a1)
            cout << x << ' ';
        cout << '\n';
        for (auto x : b1)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
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