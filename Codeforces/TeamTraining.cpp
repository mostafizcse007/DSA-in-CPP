#include <bits/stdc++.h>
using namespace std;

int max_Value(int n, int k, vector<int> &arr)
{
    sort(arr.rbegin(), arr.rend());

    int cnt = 0;
    int size = 0;

    for (auto x : arr)
    {
        size++;
        if (size * x >= k)
        {
            ++cnt;
            size = 0;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << max_Value(n, x, arr) << '\n';
    }

    return 0;
}